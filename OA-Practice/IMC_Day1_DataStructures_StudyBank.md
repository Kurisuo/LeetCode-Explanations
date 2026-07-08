# IMC OA — Day 1 Study Bank: Custom Data Structures in C++

**Rules of engagement (your style):**
- Implement each from memory. No peeking at references or STL source.
- Fill in the `// TODO` bodies yourself. The skeletons give you the *interface*, not the answer.
- After each one: run it against the listed edge cases. If it passes, move on.
- When you want a review, paste your implementation and I'll critique it — correctness, complexity, and the C++ idioms IMC will probe (const-correctness, references, overflow).
- Write in **C++** (your OA edge — avoids the Python 10s TLE trap).

**Time-realistic tiering:**
- **Tier 1 (must-do today):** Array Stack, Linked-List Stack, Ring-Buffer Queue → then all of Part B.
- **Tier 2 (if time):** Min-Heap, Hash Map (chaining), Deque, BST.
- **Tier 3 (stretch/reference):** Doubly Linked List, Trie, Union-Find.

Add at the top of every file you write:
```cpp
#include <bits/stdc++.h>
using namespace std;
// In main(): ios_base::sync_with_stdio(false); cin.tie(nullptr);
```

---

# PART A — Implement the Structures From Scratch

## Tier 1

### 1. Array-Backed Stack (dynamic, resizing)
**Goal:** a stack on a manually managed dynamic buffer — learn resize logic.

```cpp
template <typename T>
class ArrayStack {
public:
    ArrayStack();
    ~ArrayStack();

    void push(const T& val);   // amortized O(1)
    void pop();                // O(1)
    T& top();                  // O(1)
    const T& top() const;      // O(1)
    bool empty() const;        // O(1)
    size_t size() const;       // O(1)

private:
    T* data_;
    size_t size_;
    size_t capacity_;
    void resize(size_t newCap);   // TODO
};
```
**Hints:** start capacity at 1 (or a small constant); double on full; copy old → new; `delete[]` the old buffer. Decide whether you shrink on pop (most don't — why?).
**Edge cases:** push past initial capacity (triggers resize); pop to empty then push again; `top()` on empty (define behavior — throw or UB?); many pushes to force multiple resizes.
**Self-check:** push 1..1000, pop all, verify LIFO order and no leak (valgrind or mental check of every `new[]`/`delete[]`).

---

### 2. Linked-List Stack
**Goal:** same ADT, node-based — learn pointer ownership.

```cpp
template <typename T>
class ListStack {
public:
    ListStack();
    ~ListStack();

    void push(const T& val);   // O(1)
    void pop();                // O(1)
    T& top();                  // O(1)
    bool empty() const;        // O(1)
    size_t size() const;       // O(1)

private:
    struct Node {
        T val;
        Node* next;
    };
    Node* head_;
    size_t size_;
};
```
**Hints:** push = new node points to old head, head = new node. pop = save head, advance, `delete` saved. Destructor must walk and free every node.
**Edge cases:** pop on empty; destructor on a 10k-node list (no stack overflow — iterative free, not recursive); interleaved push/pop.
**Self-check:** confirm every `new` has a matching `delete`.

---

### 3. Ring-Buffer Queue (fixed capacity)
**Goal:** the classic circular queue — IMC-flavored and a common archetype.

```cpp
class CircularQueue {
public:
    explicit CircularQueue(int k);   // capacity k

    bool enqueue(int val);   // false if full,  O(1)
    bool dequeue();          // false if empty, O(1)
    int  front() const;      // -1 if empty
    int  rear()  const;      // -1 if empty
    bool isEmpty() const;
    bool isFull()  const;

private:
    vector<int> buf_;
    int head_;
    int count_;
    // rear index is derived — how?
};
```
**Hints:** track `head_` and `count_`; compute tail as `(head_ + count_) % capacity`. Using `count_` avoids the classic "full vs empty look identical" ambiguity you'd get from head==tail alone.
**Edge cases:** enqueue to full then one more (must return false); dequeue to empty; wrap-around (enqueue, dequeue, enqueue past the end index); capacity 1.
**Self-check:** fill, drain, refill across the wrap boundary; front/rear correct throughout.

## Tier 2

### 4. Binary Min-Heap / Priority Queue
**Goal:** array-backed heap — the structure behind Dijkstra (Day 2).

```cpp
class MinHeap {
public:
    void push(int val);   // O(log n)
    int  top() const;     // O(1), min element
    void pop();           // O(log n), remove min
    bool empty() const;
    size_t size() const;

private:
    vector<int> h_;
    void siftUp(size_t i);     // TODO
    void siftDown(size_t i);   // TODO
    // parent(i) = (i-1)/2 ; children = 2i+1, 2i+2
};
```
**Hints:** push = append, siftUp. pop = swap root with last, pop_back, siftDown root. siftDown must compare against the *smaller* child.
**Edge cases:** single element; duplicates; pop to empty; push after emptying; ascending vs descending insert order (both must yield sorted pops).
**Self-check:** push a shuffled 1..100, pop all → must come out 1..100 in order.

---

### 5. Hash Map (separate chaining)
**Goal:** understand collisions — IMC *will* ask how these work on video.

```cpp
class HashMap {
public:
    HashMap();
    void insert(int key, int value);   // update if exists
    bool get(int key, int& outValue) const;
    void erase(int key);
    bool contains(int key) const;

private:
    vector<list<pair<int,int>>> buckets_;
    size_t count_;
    size_t bucketIndex(int key) const;   // hash % nbuckets
    void rehash();                        // TODO: when load factor high
};
```
**Hints:** bucket = `hash(key) % buckets_.size()`; each bucket is a chain of (key,value). On insert, scan the chain to update-or-append. Rehash when `count_ / buckets_.size()` exceeds ~0.75.
**Edge cases:** collisions (force two keys into one bucket with a tiny bucket count); update existing key (no duplicate entries); erase from middle of a chain; get on absent key.
**Self-check:** insert 1000 keys with a 4-bucket start (forces rehash + collisions); verify all retrievable.

---

### 6. Deque (doubly-ended, ring buffer or list)
```cpp
class Deque {
public:
    void pushFront(int val);
    void pushBack(int val);
    void popFront();
    void popBack();
    int  front() const;
    int  back() const;
    bool empty() const;
    size_t size() const;
private:
    // TODO: doubly linked list OR resizable ring buffer with head/tail
};
```
**Hints:** cleanest as a doubly linked list with sentinel head/tail nodes (removes null-checks). Or a ring buffer where both ends move.
**Edge cases:** push both ends then drain from both; pop on empty each end; single element removed from either side.

---

### 7. Binary Search Tree (insert / search / delete / inorder)
```cpp
class BST {
public:
    void insert(int val);
    bool contains(int val) const;
    void erase(int val);              // the hard one
    vector<int> inorder() const;      // sorted output
private:
    struct Node { int val; Node* left; Node* right; };
    Node* root_ = nullptr;
    // helpers: insert(Node*&, int), erase(Node*&, int), minNode(Node*)
};
```
**Hints:** erase has three cases — leaf (delete), one child (splice), two children (replace with inorder successor = min of right subtree, then delete that). Passing `Node*&` by reference makes the recursion clean.
**Edge cases:** erase root; erase a two-child node; erase absent value; insert duplicates (decide policy); inorder must be sorted after arbitrary insert/erase sequences.
**Self-check:** insert shuffled 1..50, inorder == 1..50; erase 10 random, inorder still sorted.

## Tier 3 (stretch / reference)

### 8. Doubly Linked List (with sentinels)
Signatures: `pushBack`, `pushFront`, `erase(Node*)`, `begin/end`. Hint: dummy head+tail nodes eliminate every null edge case. Edge: erase the only node; erase head; erase tail.

### 9. Trie (prefix tree)
```cpp
class Trie {
public:
    void insert(const string& word);
    bool search(const string& word) const;      // exact
    bool startsWith(const string& prefix) const;
private:
    struct Node { array<Node*,26> next{}; bool isEnd=false; };
    Node* root_ = new Node();
};
```
Hint: walk char by char, creating nodes as needed; `search` requires `isEnd`, `startsWith` doesn't. Edge: empty string; word that's a prefix of another; search absent word sharing a prefix.

### 10. Union-Find / DSU (path compression + union by rank)
```cpp
class DSU {
public:
    explicit DSU(int n);
    int  find(int x);          // with path compression
    bool unite(int a, int b);  // false if already same set
private:
    vector<int> parent_, rank_;
};
```
Hint: `find` recursively compresses (`parent_[x] = find(parent_[x])`); `unite` attaches smaller rank under larger. Edge: unite already-connected nodes; self-union; long chain then a find (compression should flatten it).

---

# PART B — Applied Archetype Problems (do all of these today)

Same rules: signature given, you write the logic. These are the highest-probability OA patterns.

### B1. Min Stack  *(warm-up — highest probability)*
Support `push`, `pop`, `top`, and `getMin` — **all O(1)**.
```cpp
class MinStack {
public:
    void push(int val);
    void pop();
    int  top() const;
    int  getMin() const;
private:
    // TODO: what auxiliary state makes getMin O(1)?
};
```
Edge cases: duplicate minimums (pop one, min must persist); getMin after popping the current min; single element.

### B2. Max Stack variant
Same as B1 but `getMax`. Then combine: a stack supporting **both** getMin and getMax in O(1). Hint: one aux stack per extreme, storing running extremes alongside.

### B3. Queue From Two Stacks
Implement FIFO `enqueue`/`dequeue` using only two stacks. What's the amortized cost of dequeue, and why is it O(1) even though one dequeue can be O(n)?
Edge: dequeue when the "out" stack is empty (trigger the transfer); alternating enqueue/dequeue.

### B4. Daily Temperatures  *(monotonic stack)*
Given `vector<int> temps`, return `res[i]` = days until a warmer temperature (0 if none).
```cpp
vector<int> dailyTemperatures(const vector<int>& temps);
```
Hint: a decreasing monotonic stack of **indices**; when the current temp exceeds the stack-top's temp, you've found that index's answer.
Edge: strictly decreasing input (all zeros); all equal; single element; strictly increasing.

### B5. Next Greater Element II  *(circular monotonic stack)*
Circular array — for each element, the next greater element scanning circularly; -1 if none.
Hint: iterate `2n` times, index `i % n`. Edge: all equal; single element; the max element (answer -1).

### B6. Design Circular Deque
Extend your Part A ring buffer to double-ended. Edge cases as in A6.

### B7. LRU Cache  *(hard — the capstone)*
`get(key)` and `put(key,value)`, both **O(1)**, evicting least-recently-used at capacity.
```cpp
class LRUCache {
public:
    explicit LRUCache(int capacity);
    int  get(int key);            // -1 if absent, marks as recently used
    void put(int key, int value); // insert/update, evict LRU if full
private:
    // TODO: hash map (key -> list iterator) + doubly linked list of (key,value)
};
```
Hint: `unordered_map<int, list<pair<int,int>>::iterator>` + a `list` for recency order. `list::splice` moves a node to the front in O(1). On eviction, remove from list back **and** erase its map entry (don't forget the map!).
Edge: put an existing key (update + promote, no eviction); get promotes; capacity 1; evict then re-insert the evicted key.

### B8. (Stretch) Design a Stack With Increment
`push`, `pop`, and `increment(k, val)` — add `val` to the bottom `k` elements. Naive increment is O(k); can you make it O(1) amortized with a lazy delta array? Edge: k larger than size; increment then pop (the popped value must include the delta).

---

# End-of-Day Self-Assessment
You're ready for Day 2 when:
- [ ] Array Stack, Linked Stack, Ring Queue implemented from memory, no reference.
- [ ] Min Stack + Daily Temperatures + Next Greater II solved (the three highest-probability patterns).
- [ ] LRU Cache solved (this is the "hard" archetype).
- [ ] You can explain, out loud, hash-map collision handling and why LRU needs *both* a map and a list — that's the video-round prep.

Paste any implementation for review and I'll check correctness, complexity, and the exact idioms IMC probes (const-correctness, reference-passing, overflow, resize logic).
