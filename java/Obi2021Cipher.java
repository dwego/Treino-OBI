import java.util.List;
import java.util.Scanner;

public class Obi2021Cipher {

    private final static String ALPHABET = "abcdefghijklmnopqrstuvwxyz";
    private final static String VOGAIS_LISTA = "aeiou";
    private final static List<Integer> vogais = List.of(0, 4, 8, 14, 20);

    private static char proxima_consoante(char c) {
        for (int i = ALPHABET.indexOf(c) + 1; i < ALPHABET.length(); i++) {
            char proxima = ALPHABET.charAt(i);
            if (VOGAIS_LISTA.indexOf(proxima) == -1) {
                return proxima;
            }
        }
        return c;
    }

    private static char vogal_mais_perto(char c) {
        int index_c = ALPHABET.indexOf(c);
        int index_vogal1 = 0;
        int index_vogal2 = 0;

        for (int i = 0; i < vogais.size() - 1; i++) {
            index_vogal1 = vogais.get(i);
            index_vogal2 = vogais.get(i + 1);

            if (index_vogal1 < index_c && index_c < index_vogal2) {
                int menor_1 = Math.abs(index_c - index_vogal1);
                int menor_2 = Math.abs(index_c - index_vogal2);
                if (menor_1 == menor_2 || menor_1 < menor_2) {
                    return ALPHABET.charAt(index_vogal1);
                }
                return ALPHABET.charAt(index_vogal2);
            }
        }

        return ALPHABET.charAt(index_vogal2);
    }

    private static String codificar(String frase) {
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < frase.length(); i++) {
            char c = frase.charAt(i);

            if (VOGAIS_LISTA.indexOf(c) != -1) {
                result.append(c);
                continue;
            }

            result.append(c);
            char vogal = vogal_mais_perto(c);
            result.append(vogal);
            c = proxima_consoante(c);
            result.append(c);
        }

        return result.toString();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String phrase = in.nextLine();
        String frase_codificada = codificar(phrase);

        System.out.println(frase_codificada);

    }
}
