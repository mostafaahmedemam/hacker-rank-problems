using System;

namespace ConsoleApp1
{
    public class Solution
    {
        public int[] TwoSum(int[] nums, int target)
        {
            Array.Sort(nums);
            //Console.WriteLine(nums[0]);
            int[] output = new int[2];
            int mutex = 0;
            for (int i = 0; i < nums.Length - 1; i++)
            {
                if (nums[i] + nums[i + 1] <= target)
                {
                    output[0] = i;
                    output[1] = (i + 1);
                    return output;
                }
            }
            return output;
        }
        public static double Compute(Func<double, double> fx, double a, double b)
        {
            double h = 0.5;
            double n = (b - a)/h ;
            
            double sum = fx(a) + fx(b);
            double x = a;
            for (int j = 1; j < n; j++)
            {
                x += h;
                if (j % 2 != 0)
                {
                    sum += 4 * fx(x);
                }
                else
                {
                    sum += 2 * fx(x);
                }
            }

            return sum * h / 3;
        }

    }
    internal class Program
    {
        static void Main(string[] args)
        {
            Solution solu = new Solution();
            Console.WriteLine(Solution.Compute(x => Math.Exp(x)-Math.Exp(-x), -23, 25));

            //Console.WriteLine(Solution.Compute(x => 7 - (x* x * x * x), -1, 2));
            //int[] nums = new int []{ 3, 2, 4 };
            //int[] output= solu.TwoSum(nums,6);
            //Console.WriteLine(output[0]+" -*---- "+output[1]);
        }
    }
}
