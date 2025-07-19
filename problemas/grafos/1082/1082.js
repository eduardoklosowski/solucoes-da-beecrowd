var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

const DFS = (visitado, grafo, componente, u) => {
    visitado[u] = componente;

    for (let i = 0; i < grafo[u].length; ++i) {
        let v = grafo[u][i];

        if (visitado[v] === 0) {
            DFS(visitado, grafo, componente, v);
        }
    }
};

let N = parseInt(lines.shift());
for (let k = 1; k <= N; ++k) {
    let [V, E] = lines.shift().trim().split(' ').map(x => parseInt(x));

    let grafo = [];
    let visitado = [];
    for (let i = 0; i < V; ++i) {
        grafo.push([]);
        visitado.push(0);
    }

    let aCharCode = 'a'.charCodeAt();
    for (let i = 0; i < E; ++i) {
        let [u, v] = lines.shift().trim().split(' ');

        grafo[u.charCodeAt(0) - aCharCode].push(v.charCodeAt(0) - aCharCode);
        grafo[v.charCodeAt(0) - aCharCode].push(u.charCodeAt(0) - aCharCode);
    }

    console.log(`Case #${k}:`);
    let componentes = 0;
    for (let u = 0; u < V; ++u) {
        if (visitado[u] === 0) {
            componentes += 1;
            DFS(visitado, grafo, componentes, u);

            let vertices = visitado.map((x, i) => x === componentes ? String.fromCharCode(i + aCharCode) : null).filter(x => x !== null);
            vertices.sort();
            console.log(`${vertices.join(',')},`);
        }
    }
    console.log(`${componentes} connected components`);
    console.log('');
}