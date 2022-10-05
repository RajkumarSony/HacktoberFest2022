package searchalgorithm;

import exception.RangeException;

public interface ISearch<T> {

    public T search(T t);

    public T searchBetween(T t, int start, int end) throws RangeException;

}
