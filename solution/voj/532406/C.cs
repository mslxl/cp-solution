using System;
using System.Collections.Generic;
using System.Linq;
public class Program{
  public static void Main(string[] args){
    int t = int.Parse(Console.ReadLine());
    for(int i = 0; i < t; i++){
        int[] header = Console.ReadLine()
          .Split(' ')
          .Select(e => int.Parse(e))
          .ToArray();
        int[] v = Console.ReadLine()
          .Split(' ')
          .Select(e => int.Parse(e))
          .ToArray();

        int ans = v.Where(e => e > v[header[1]-1])
          .ToArray()
          .Length;

        Console.WriteLine(ans);
    }
  }
}