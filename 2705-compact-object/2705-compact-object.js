var compactObject = function(obj) {
    if (Array.isArray(obj)) {
        let res = [];

        for (let x of obj) {
            if (x) {
                res.push(typeof x === "object" ? compactObject(x) : x);
            }
        }

        return res;
    }

    let res = {};

    for (let key in obj) {
        if (obj[key]) {
            res[key] = typeof obj[key] === "object"
                ? compactObject(obj[key])
                : obj[key];
        }
    }

    return res;
};