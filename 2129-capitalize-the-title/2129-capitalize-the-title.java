class Solution {
    public String capitalizeTitle(String title) {
        String[] arr;
        arr=title.split(" ");
        String output="";
        for(int i=0;i<arr.length;i++)
        {
            System.out.println(arr[i]);
            if(arr[i].length()<3)
                arr[i]=arr[i].toLowerCase();
            else
            {
                arr[i]=arr[i].toLowerCase();
               arr[i]=arr[i].substring(0,1).toUpperCase()+arr[i].substring(1);
            }
            System.out.println(arr[i]);
        }
        return String.join(" ",arr);
    }
}