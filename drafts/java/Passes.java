public class Passes {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);


        int N = 10;
        int contador = 0;
        int backup = 0;
        int passes_v = 0;
        int passes_a = 0;
        while (contador < N) {
            int jogador = s.nextInt(); /// 20
            if (backup == 0) {
                backup = jogador; // 10
                continue;
            }

            if (backup > 0 && jogador > 0) {
                passes_v++;
            } if (backup < 0 && jogador < 0) {
                passes_a++;
            }

            backup = jogador;
        }

        System.out.println(passes_v + " " + passes_a);

    }
}
