function memoize(fn) {
  const cache = new Map();
  let callCount = 0;

  const memoized = function(...args) {
    const key = JSON.stringify(args); // unique key for this argument list

    if (cache.has(key)) {
      return cache.get(key);
    }

    callCount++;
    const result = fn(...args);
    cache.set(key, result);
    return result;
  };

  // LeetCode’s test harness uses this to read callCount
  memoized.getCallCount = function() {
    return callCount;
  };

  return memoized;
}