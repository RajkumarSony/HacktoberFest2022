package searchalgorithm;

import java.util.Comparator;

import exception.RangeException;

public class BinarySearch<T> implements ISearch<T> {

    private final T[] objects;

    private Comparator<T> comparator;

    public BinarySearch(T[] objects, Comparator<T> comparator) {
        this.objects = objects;
        this.comparator = comparator;
    }

    @Override
    public T search(T object) {
        return searchInternal(object, 0, objects.length);
    }

    @Override
    public T searchBetween(T object, int start, int end) throws RangeException {
        if (start < 0 || end >= objects.length)
            throw new RangeException("This is not a valid range.");

        return searchInternal(object, start, end);
    }

    private T searchInternal(T object, int start, int end) {
        int s = start, e = end, mid = 0, r = 0;

        while (s <= e) {
            mid = (s + e) / 2;
            r = comparator.compare(object, objects[mid]);

            if (r == 0)
                return objects[mid];

            if (r < 0)
                e = mid - 1;
            else
                s = mid + 1;
        }

        return null;
    }

}