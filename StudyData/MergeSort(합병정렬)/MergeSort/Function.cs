using System;

namespace MergeSort
{
    public class Function
    {

        //합병정렬
        public void MergeSort(int[] S)
        {
            Divide(0,S.Length-1,S);
        }

        //분할작업
        public void Divide(int head,int tail,int[] S)
        {
            int mid = 0;        //배열을 반으로 분할하기 전에 분할할 지점을 나타내는 변수

            if (head != tail)      //배열의 길이가 1일 경우 작동하지않음(머리랑 꼬리가 같으면 당연히 배열의 길이는 1이다.)
            {              
                if ((head + tail) % 2 == 0)    //분할할 부분이 짝수일경우
                {
                    mid = (head + tail) / 2;
                }
                else if ((head + tail) % 2 == 1)   //분할할 부분이 홀수일경우
                {
                    mid = (head + tail - 1) / 2;
                }

                Divide(head, mid, S);
                Divide(mid+1, tail, S);
                Merge(head, mid, tail, S);      
            }
        }

        //합병작업
        public void Merge(int f,int m, int l,int[] S)
        {
            int[] ArrayA = new int[m - f + 1];
            int[] ArrayB = new int[l - m];
            int Arraycount = f;         //S배열에서 위치를 지정해주는 변수
            int Acount = 0;             //A배열에서 위치를 지정해주는 변수
            int Bcount = 0;             //B배열에서 위치를 지정해주는 변수

            bool ArrayA_Out = false;    //A배열을 모두 검사했는지 체크
            bool ArrayB_Out = false;    //B배열을 모두 검사했는지 체크

            for (int n = 0; n < ArrayA.Length; n++) //배열에 값배정
            {
                ArrayA[n] = S[f + n];
            }

            for (int n = 0; n < ArrayB.Length; n++) //배열에 값배정
            {
                ArrayB[n] = S[m + n + 1];
            }

            while (Arraycount < l+1) {
                if (ArrayA[Acount] < ArrayB[Bcount])
                {
                    if (ArrayA_Out == false)        //A배열의 값을 할당해줌
                    {
                        S[Arraycount] = ArrayA[Acount];
                        Acount++;
                    }
                    else         //A배열은 모두 검사했으니 B배열의 값을 할당해줌
                    {
                        S[Arraycount] = ArrayB[Bcount];
                        Bcount++;
                    }
                    if (Acount > ArrayA.Length - 1)
                    {
                        Acount = ArrayA.Length - 1;
                        ArrayA_Out = true;       //A배열 모두 검사 완료
                    }


                }
                else if(ArrayA[Acount] >= ArrayB[Bcount])
                {
                    if (ArrayB_Out == false)        //B배열의 값을 할당해줌
                    {
                        S[Arraycount] = ArrayB[Bcount];
                        Bcount++;
                    }
                    else          //B배열은 모두 검사했으니 A배열의 값을 할당해줌
                    {
                        S[Arraycount] = ArrayA[Acount];
                        Acount++;
                    }

                    if (Bcount > ArrayB.Length - 1)
                    {
                        Bcount = ArrayB.Length - 1;
                        ArrayB_Out = true;      //B배열 모두 검사 완료
                    }
                }
                Arraycount++;
            }
        }

        //배열산출
        public void Print(int[] S)
        {
            for (int n = 0; n < S.Length; n++)
            {
                Console.Write(S[n]);
                if (n != S.Length - 1)
                {
                    Console.Write(", ");
                }
                else
                {
                    Console.WriteLine("");
                }
            }
        }
    }
}
