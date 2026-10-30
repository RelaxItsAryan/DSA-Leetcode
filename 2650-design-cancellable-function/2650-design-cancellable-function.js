var cancellable = function(generator) {
    let cancelled = false;

    const cancel = () => {
        cancelled = true;
    };

    const promise = new Promise((resolve, reject) => {
        const step = (method, value) => {
            let result;

            try {
                result = generator[method](value);
            } catch (error) {
                reject(error);
                return;
            }

            if (result.done) {
                resolve(result.value);
                return;
            }

            result.value.then(
                (resolvedValue) => {
                    if (cancelled) {
                        step("throw", "Cancelled");
                    } else {
                        step("next", resolvedValue);
                    }
                },
                (error) => {
                    step("throw", error);
                }
            );
        };

        step("next", undefined);
    });

    return [cancel, promise];
};