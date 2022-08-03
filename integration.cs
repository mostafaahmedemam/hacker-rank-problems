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
        public static double Compute(Func<double, double> fx, double a, double b, int n)
        {
            double h = (b - a) / n;

            double sum = fx(a) + fx(b);
            double x = a;
            for (int j = 1; j < n; j++)
            {
                x += h;
                sum += (2 << (j % 2)) * fx(x);
            }

            return sum * h / 3;
        }

    }
    internal class Program
    {
        static void Main(string[] args)
        {
            Solution solu = new Solution();
            Console.WriteLine(Solution.Compute(x => 7 - (x * x * x), -1, 2, 6));
            //int[] nums = new int []{ 3, 2, 4 };
            //int[] output= solu.TwoSum(nums,6);
            //Console.WriteLine(output[0]+" -*---- "+output[1]);
        }
    }
}
