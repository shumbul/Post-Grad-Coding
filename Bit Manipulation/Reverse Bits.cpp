// https://www.interviewbit.com/problems/reverse-bits

unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    unsigned int B=0;
    int k=0;
    while(k++<32){
        B=B<<1;
        // cout<<B<<" ";
        B=B|(A&1);
        A=A>>1;
    }
    return B;
}

/*
Time, Space: O(1)
*/
