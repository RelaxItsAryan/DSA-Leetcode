/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let value = init;

    return {
        increment: function() {
            value += 1;
            return value;
        },
        decrement: function() {
            value -= 1;
            return value;
        },
        reset: function() {
            value = init;
            return value;
        }
    };
};