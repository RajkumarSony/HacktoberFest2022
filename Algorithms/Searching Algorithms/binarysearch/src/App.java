import java.util.Comparator;

import exception.RangeException;
import searchalgorithm.BinarySearch;
import searchalgorithm.ISearch;

public class App {
    public static void main(String[] args) {

        Comparator<Integer> comparator = new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return a.compareTo(b);
            }
        };

        ISearch<Integer> searchObject = new BinarySearch<Integer>(
                new Integer[] { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 }, comparator);

        System.out.println(searchObject.search(512));

        try {
            System.out.println(searchObject.searchBetween(512, 0, 7));
        } catch (RangeException e) {
            e.printStackTrace();
        }
    }
}
