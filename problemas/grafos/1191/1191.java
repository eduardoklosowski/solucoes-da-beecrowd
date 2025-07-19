import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
  public static class No {
    public char letra;
    public No esquerda;
    public No direita;

    No(char letra) {
      this.letra = letra;
      this.esquerda = null;
      this.direita = null;
    }
  }

  public static String prefixa;
  public static StringBuilder sb;
  public static int indice_prefixa;

  public static No leArvore(String infixa) {
    char letra = prefixa.charAt(indice_prefixa);
    indice_prefixa += 1;
    No arvore = new No(letra);
    int indice_infixa = infixa.indexOf(letra);

    String infixa_esquerda = infixa.substring(0, indice_infixa);
    String infixa_direita = infixa.substring(indice_infixa + 1, infixa.length());

    if(infixa_esquerda.length() > 0) {
      arvore.esquerda = leArvore(infixa_esquerda);
    }
    if(infixa_direita.length() > 0) {
      arvore.direita = leArvore(infixa_direita);
    }

    return arvore;
  }

  public static void posFixa(No arvore) {
    if(arvore == null) {
      return;
    }

    posFixa(arvore.esquerda);
    posFixa(arvore.direita);
    sb.append(arvore.letra);
  }

  public static void main(String[] args) throws IOException {
    InputStreamReader ir = new InputStreamReader(System.in);
    BufferedReader in = new BufferedReader(ir);

    sb = new StringBuilder();

    while(in.ready()) {
      String linha = in.readLine().trim();
      if(linha.equals("")) {
        continue;
      }

      String[] percursos = linha.split(" ");
      prefixa = percursos[0].trim();
      String infixa = percursos[1].trim();

      indice_prefixa = 0;
      No arvore = leArvore(infixa);
      posFixa(arvore);
      sb.append('\n');
    }

    System.out.print(sb.toString());
  }
}