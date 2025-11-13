process.stdin.resume();
process.stdin.setEncoding('utf8');

let input = '';
let lineCount = 0;

process.stdin.on('data', (chunk) => {
  input += chunk;
});

process.stdin.on('end', () => {
  const lines = input.trim().split('\n');

  let n: number = 0;
  let m: number = 0;
  let grafo: boolean[][] = [];
  let visitados: Set<number> = new Set();

  const DFS = (vertice: number, espacamento: number): boolean => {
    let foi_pra_frente = false;
    visitados.add(vertice);

    for (let vizinho = 0; vizinho < n; ++vizinho) {
      if (!(grafo[vertice][vizinho])) {
        continue;
      }
      let linha = `${(' '.repeat(espacamento))}${vertice}-${vizinho}`;
      if (!(visitados.has(vizinho))) {
        linha += ` pathR(G,${vizinho})`;
        console.log(linha);
        foi_pra_frente = true;
        DFS(vizinho, espacamento + 2);
      } else {
        console.log(linha);
      }
    }

    return foi_pra_frente;
  };

  let p = 0;
  const T = parseInt(lines[p++]!);

  for (let k = 0; k < T; ++k) {
    [n, m] = lines[p++].trim().split(' ')!.map(x => parseInt(x));

    grafo = [];
    for (let i = 0; i < n; ++i) {
      grafo.push([]);
    }

    for (let i = 0; i < m; ++i) {
      const [u, v] = lines[p++].trim().split(' ')!.map(x => parseInt(x));
      grafo[u][v] = true;
    }

    console.log(`Caso ${k + 1}:`);

    visitados.clear();
    for (let i = 0; i < n; ++i) {
      if (!(visitados.has(i))) {
        if (DFS(i, 2)) {
          console.log('');
        }
      }
    }
  }
});