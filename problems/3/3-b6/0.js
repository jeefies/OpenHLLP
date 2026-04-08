const fs = require('fs');

function write(x, t) {
    let res = '';
    while (t--) {
        if (x) res += Math.ceil(Math.random() * 9).toString();
        else res += '0';
    }
    return res;
}

for (let i = 0; i < 1024; i++) {
    x = '';
    x += write(i >> 9 & 1, 1);
    x += write(i >> 8 & 1, 1);
    x += write(i >> 7 & 1, 1);
    x += write(i >> 6 & 1, 2);
    x += write(i >> 5 & 1, 1);
    x += write(i >> 4 & 1, 1);
    x += write(i >> 3 & 1, 2);
    x += write(i >> 2 & 1, 1);
    x += '.';
    x += write(i >> 1 & 1, 1);
    x += write(i >> 0 & 1, 1);
    while (x.charAt(0) == '0' && x.charAt(1) != '.') {
        x = x.slice(1);
    }
    while (x.charAt(x.length - 1) == '0' && x.charAt(x.length - 2) != '.' && Math.random() < 0.5) {
        x = x.slice(0, -1);
    }
    if (x.charAt(x.length - 1) == '.') {
        x = x.slice(0, -1);
    }
    fs.writeFileSync(`${i + 1}.in`, x + '\n');
}