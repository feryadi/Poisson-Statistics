package com.company;

import java.math.BigDecimal;
import java.math.RoundingMode;

public class Main {



    public static void main(String[] args) {



        double a[] = {3.4, 3.6, 4.4, 5.9, 6.4, 7.2, 7.9, 9.0, 9.9, 10.4, 10.9, 11.6, 12.4, 13.7, 14.0, 15.2, 15.8, 15.9, 17.5, 17.7, 19.0, 20.1,
                21.3, 21.7, 22.3, 22.6, 23.4, 24.4, 25.7, 27.1, 28.1, 29.5, 30.1, 31.0, 32.0, 32.4, 34.2, 35.4, 35.5, 35.9, 36.1, 36.2, 37.2, 37.4, 38.8, 41.7,
                43.0, 44.3, 45.8, 47.1, 48.8, 49.4, 50.0, 50.3, 51.3, 51.6, 52.4, 52.9, 54.4, 55.2, 56.4, 56.8, 58.9, 62.0, 62.7, 63.4, 63.7, 64.0, 66.0,
                66.9, 70.2, 70.7, 72.3, 72.7, 73.6, 74.0, 75.3, 75.6, 77.1, 79.0, 81.0, 82.8, 83.5, 83.7, 84.3, 85.5, 86.3, 86.9, 87.8, 88.2,
                88.6, 89.3, 89.9, 90.7, 91.8, 92.0, 93.7, 95.0, 95.9, 97.0, 98.9, 99.3, 99.9, 100.6, 101.0, 102.0, 102.9, 103.8, 107.0, 108.1,
                108.6, 108.8, 109.9, 110.3, 110.5, 111.0, 111.4, 112.0, 114.1};


        differenceBetweenOne(a);
        System.out.println();
        differenceBetweenTwo(a);

    }

    private static void differenceBetweenOne(double[] array1) {
        for (int n = 0; n < array1.length-1; n++) {
            double difference = array1[n + 1] - array1[n];
            System.out.print(round(difference,2));
            System.out.print(", ");
        }
    }

    private static void differenceBetweenTwo(double[] array1) {
        for (int n = 0; n < array1.length-2; n++) {
            double difference = array1[n + 2] - array1[n];
            System.out.print(round(difference,2));
            System.out.print(", ");
        }
    }



    public static double round(double value, int places) {
        if (places < 0) throw new IllegalArgumentException();

        BigDecimal bd = new BigDecimal(value);
        bd = bd.setScale(places, RoundingMode.HALF_UP);
        return bd.doubleValue();
    }

}
