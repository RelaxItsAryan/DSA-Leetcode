/**
 * @param {Array} arr
 * @param {number} n
 * @return {Array}
 */
var flat = function (arr, n) {
  const result = [];

  function helper(current, depth) {
    for (const item of current) {
      if (Array.isArray(item) && depth < n) {
        // Flatten this subarray by recursing with increased depth
        helper(item, depth + 1);
      } else {
        // Push numbers or subarrays that should not be flattened
        result.push(item);
      }
    }
  }

  helper(arr, 0);
  return result;
};