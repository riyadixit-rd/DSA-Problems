var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        let n = functions.length;
        let result = new Array(n);
        let completed = 0;

        functions.forEach((fn, i) => {
            fn()
                .then(value => {
                    result[i] = value;
                    completed++;

                    if (completed === n) {
                        resolve(result);
                    }
                })
                .catch(reject);
        });
    });
};