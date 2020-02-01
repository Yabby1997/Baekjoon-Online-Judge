public class Test {
    long sum(int[] a) {
        long ans = 0;
        for(int i = 0; i < a.length; i++)        //length() for String, .length is variable of array
            ans = ans + a[i];
        return ans;
    }
}


