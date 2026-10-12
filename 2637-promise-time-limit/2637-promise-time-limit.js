var timeLimit = function(fn, t) {
  return function(...args) {
    const timeout = new Promise((_, reject) => {
      setTimeout(() => reject("Time Limit Exceeded"), t);
    });

    const result = Promise.resolve().then(() => fn(...args));

    return Promise.race([result, timeout]);
  };
};