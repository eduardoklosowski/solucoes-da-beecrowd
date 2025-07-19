import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
	public static void DFS(ArrayList<Integer> visitado, ArrayList<ArrayList<Integer>> grafo, int componente, int u){
		visitado.set(u, componente);

		for(int i = 0; i < grafo.get(u).size(); ++i){
			int v = grafo.get(u).get(i);

			if(visitado.get(v) == 0){
				DFS(visitado, grafo, componente, v);
			}
		}
	}
	
    public static void main(String[] args) throws IOException {
        InputStreamReader ir = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(ir);

        int N = Integer.parseInt(in.readLine());
		for(int k = 1; k <= N; ++k){
			String[] VE = in.readLine().trim().split(" ");
			int V = Integer.parseInt(VE[0]);
			int E = Integer.parseInt(VE[1]);

			ArrayList<Integer> visitado = new ArrayList<Integer>(); 
			ArrayList<ArrayList<Integer>> grafo = new ArrayList<ArrayList<Integer>>();
			for(int i = 0; i < V; ++i){
				visitado.add(0);
				grafo.add(new ArrayList<Integer>());
			}

			for(int i = 0; i < E; ++i){
				String[] uv = in.readLine().trim().split(" ");
				char u = uv[0].charAt(0);
				char v = uv[1].charAt(0);

				grafo.get(u - 'a').add(v - 'a');
				grafo.get(v - 'a').add(u - 'a');
			}

			System.out.printf("Case #%d:\n", k);
			int componentes = 0;
			for(int u = 0; u < V; ++u){
				if(visitado.get(u) == 0){
					componentes += 1;
					DFS(visitado, grafo, componentes, u);

					ArrayList<String> vertices = new ArrayList<String>();
					for(int i = 0; i < V; ++i){
						if(visitado.get(i) == componentes){
							vertices.add(Character.toString((char)(i + (int)'a')));
						}
					}

					Collections.sort(vertices);

					System.out.printf(String.join(",", vertices));
					System.out.println(",");
				}
			}
			System.out.printf("%d connected components\n\n", componentes);
		}
    }
}