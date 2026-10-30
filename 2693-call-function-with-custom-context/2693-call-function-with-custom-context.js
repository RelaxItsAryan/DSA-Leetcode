/**
 * @param {Object} obj
 * @param {*[]} args
 * @return {*}
 */
Function.prototype.callPolyfill = function(obj, ...args) {
    const context = Object(obj);

    const symbolKey = Symbol("callPolyfill");
    context[symbolKey] = this;

    try {
        return context[symbolKey](...args);
    } finally {
        delete context[symbolKey];
    }
};