/**
 * @param {MultidimensionalArray} arr
 * @return {Generator<number, void, unknown>}
 */
function* inorderTraversal(arr) {
    for (const item of arr) {
        if (Array.isArray(item)) {
            yield* inorderTraversal(item);
        } else {
            yield item;
        }
    }
}