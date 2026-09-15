var TimeLimitedCache = function() {
  this.cache = new Map(); // key -> { value, timeoutId }
};

/**
 * @param {number} key
 * @param {number} value
 * @param {number} duration - milliseconds until expiration
 * @return {boolean} - true if an un-expired key already existed, else false
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
  const existing = this.cache.get(key);
  const alreadyExists = existing !== undefined;

  // If key already exists, clear its old timeout so it doesn't delete early
  if (alreadyExists) {
    clearTimeout(existing.timeoutId);
  }

  // Set new timeout to remove the key after `duration` ms
  const timeoutId = setTimeout(() => {
    this.cache.delete(key);
  }, duration);

  this.cache.set(key, { value, timeoutId });

  return alreadyExists;
};

/**
 * @param {number} key
 * @return {number} - value if un-expired key exists, else -1
 */
TimeLimitedCache.prototype.get = function(key) {
  const entry = this.cache.get(key);
  if (entry === undefined) {
    return -1;
  }
  return entry.value;
};

/**
 * @return {number} - count of un-expired keys
 */
TimeLimitedCache.prototype.count = function() {
  return this.cache.size;
};