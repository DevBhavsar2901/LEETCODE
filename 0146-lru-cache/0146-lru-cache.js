/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) {
    this.cap = capacity;
    this.mp = new Map();
};

/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    if(!this.mp.has(key)) return -1;
    let val = this.mp.get(key);
    this.mp.delete(key);
    this.mp.set(key, val);
    return val;
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    if(this.mp.has(key)) this.mp.delete(key);
    this.mp.set(key, value);
    if(this.mp.size > this.cap) {
        let k = this.mp.keys().next().value;
        this.mp.delete(k);
    }
};

/** 
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */