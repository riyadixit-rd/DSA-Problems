var TimeLimitedCache = function() {
    this.cache = new Map();
};

TimeLimitedCache.prototype.set = function(key, value, duration) {
    const now = Date.now();
    const exists = this.cache.has(key) &&
                   this.cache.get(key).expire > now;

    this.cache.set(key, {
        value: value,
        expire: now + duration
    });

    return exists;
};

TimeLimitedCache.prototype.get = function(key) {
    if (!this.cache.has(key)) return -1;

    const item = this.cache.get(key);

    if (item.expire <= Date.now()) {
        this.cache.delete(key);
        return -1;
    }

    return item.value;
};

TimeLimitedCache.prototype.count = function() {
    const now = Date.now();
    let count = 0;

    for (const [key, item] of this.cache) {
        if (item.expire > now) {
            count++;
        } else {
            this.cache.delete(key);
        }
    }

    return count;
};