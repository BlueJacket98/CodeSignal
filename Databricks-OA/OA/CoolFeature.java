package OA;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

//最开始有3个case超时，原因是每次执行问加起来等于target的情况有多少种的那个query时，我都是 重新算一遍记录b数组每个数出现次数的HashMap，其实只用最开始构好，然后每次做第二种 query([index, num])，更新一下HashMap就行。改了就过了。
//Give three array ​a​, ​b​ and ​query​. This one is hard to explain. Just read the example.
//Input:
//a = [1, 2, 3]
//b = [3, 4]
//query = [[1, 5], [1, 1, 1], [1, 5]]
//Output:
//[2, 1]
//Explain:
//Just ignore every first element in sub-array in the query.
//So we will get a new query like this query = [[5], [1, 1], [5]]
//Only record the result when meet the single number in new query array.
//And the rule of record is find the sum of the single number.
//The example above is 5 = 1 + 4 and 5 = 2 + 3, there are two result.
//So currently the output is [2]
//When we meet the array length is larger than 1, such as [1, 1]. That means we will replace the b[x] = y, x is the first element, y is second element. So in this example, the b will be modify like this b = [1, 4]
//And finally, we meet the [5] again. So we will find sum again. This time the result is 5 = 1 + 4. So currently the output is [2, 1]
//note: Don't have to modify the query array, just ignore the first element.
//Time:
//Function findSum is O(a * b)
//Function modifyArrayb is O(1)
//Function treverse is O(query)
//So total maybe O(a * b * query)
//I think this problem must has some better solution, but I am almost run out of time.
//动态修改mapB
public class CoolFeature {
    public List<Integer> solution(int[] a, int[] b, int[][] query){
        if(a==null || b== null || query==null) return new ArrayList<>();
        Map<Integer, Integer> mapA = new HashMap<>();
        Map<Integer, Integer> mapB = new HashMap<>();
        for(int i=0; i<a.length; i++){
            mapA.put(a[i], mapA.getOrDefault(a[i], 0)+1);
        }

        for(int i=0; i<b.length; i++){
            mapB.put(b[i], mapB.getOrDefault(b[i], 0)+1);
        }
        List<Integer> res = new ArrayList<>();
        for(int[] arr: query){
            if(arr.length == 3){
                int oldval = b[arr[1]];
                mapB.put(oldval, mapB.get((oldval))-1);
                int newval = arr[2];
                mapB.put(newval, mapB.getOrDefault(newval, 0)+1);
            }else{
                int target = arr[1];
                int count = 0;
                for(int key : mapA.keySet()){
                    int val = target-key;
                    if(mapB.containsKey(val)){
                        count+=mapA.get(key)*mapB.get(val);
                    }
                }
                res.add(count);
            }
        }

        return res;
    }

    public static void main(String[] args){
        int[] a = new int[]{1,2,3};
        int[] b = new int[]{3,4};
        int[][] query = new int[][]{{1,5}, {1,1,1}, {1,5}};
        CoolFeature cf = new CoolFeature();
        System.out.print(cf.solution(a, b, query));

    }
}
