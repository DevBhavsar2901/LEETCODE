class Node {
    constructor(key, val) {
        this.key = key;
        this.val = val;
        this.freq = 1;
        this.prev = null;
        this.next = null;
    }
}
class DLL {
    constructor() {
        this.head = new Node(0, 0);
        this.tail = new Node(0, 0);
        this.head.next = this.tail;
        this.tail.prev = this.head;
        this.size = 0;
    }
    add(node) {
        node.next = this.head.next;
        node.prev = this.head;
        this.head.next.prev = node;
        this.head.next = node;
        this.size++;
    }
    remove(node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
        this.size--;
    }
    removeLast() {
        if (this.size === 0) return null;
        let node = this.tail.prev;
        this.remove(node);
        return node;
    }
}
/**
 * @param {number} capacity
 */
var LFUCache = function(capacity) {
    this.cap = capacity;
    this.minFreq = 0;
    this.keyMap = new Map();
    this.freqMap = new Map();
};
LFUCache.prototype.update = function(node) {
    let f = node.freq;
    this.freqMap.get(f).remove(node);
    if (f === this.minFreq && this.freqMap.get(f).size === 0) this.minFreq++;
    node.freq++;
    if (!this.freqMap.has(node.freq)) this.freqMap.set(node.freq, new DLL());
    this.freqMap.get(node.freq).add(node);
};
/**
 * @param {number} key
 * @return {number}
 */
LFUCache.prototype.get = function(key) {
    if (!this.keyMap.has(key)) return -1;
    let node = this.keyMap.get(key);
    this.update(node);
    return node.val;
};

/**
 * @param {number} key
 * @param {number} value
 * @return {void}
 */
LFUCache.prototype.put = function(key, value) {
    if (this.cap === 0) return;
    if(this.keyMap.has(key)) {
        let node = this.keyMap.get(key);
        node.val = value;
        this.update(node);
        return;
    }
    if(this.keyMap.size === this.cap) {
        let list = this.freqMap.get(this.minFreq);
        let node = list.removeLast();
        this.keyMap.delete(node.key);
    }
    let node = new Node(key, value);
    this.minFreq = 1;
    if (!this.freqMap.has(1)) this.freqMap.set(1, new DLL());
    this.freqMap.get(1).add(node);
    this.keyMap.set(key, node);
};