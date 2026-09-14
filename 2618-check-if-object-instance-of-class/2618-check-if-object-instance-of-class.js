/**
 * @param {any} obj
 * @param {any} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    // null and undefined are not instances of any class
    if (obj === null || obj === undefined) {
        return false;
    }

    // classFunction must be a valid function
    if (typeof classFunction !== "function") {
        return false;
    }

    let current = Object(obj);

    while (current !== null) {
        if (Object.getPrototypeOf(current) === classFunction.prototype) {
            return true;
        }

        current = Object.getPrototypeOf(current);
    }

    return false;
};