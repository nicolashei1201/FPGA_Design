#include <stdio.h>
#include "xil_printf.h"
#include "xil_io.h"
#include "xparameters.h"
#include "parity.h"
#include "PWM.h"
#include "djb2.h"
#include "calculator.h"
#include "sorting.h"


int main()
{
	int sl=0;
	u32	A,B,C,D,P,C_out;
	u32 sort_out[4];
	u32 reset;
	u32 r;
	u32 g;
	u32 b;
	char str[4];

	printf("Program Start.\n\r");
	while(getchar() != EOF) {

		printf("==========================\r\n");
		printf("1 = sort\r\n");
		printf("2 = ALU\r\n");
		printf("3 = parity\r\n");
		printf("4 = hash function\r\n");
		printf("5 = PWM control\r\n");
		printf("==========================\r\n");
		printf("Please select mode:");
		scanf("%d", &sl);
		printf(" %d\r\n", sl);

		switch(sl){
			case 1:
				printf("Input A:");
				scanf("%d", &A);
				printf(" %d\r\n", A);
				printf("Input B:");
				scanf("%d", &B);
				printf(" %d\r\n", B);
				printf("Input C:");
				scanf("%d", &C);
				printf(" %d\r\n", C);
				printf("Input D:");
				scanf("%d", &D);
				printf(" %d\r\n", D);

				int i;
				for(i=0;i<4;i++){
					sort_out[i] = sorting(XPAR_SORTING_0_S00_AXI_BASEADDR,A,B,C,D,i);
				}

				printf("\r\nResult of sort is : %d , %d , %d, %d\r\n\r\n",sort_out[0], sort_out[1], sort_out[2], sort_out[3]);
				break;

			case 2:
				printf("Input A:");
				scanf("%d", &A);
				printf(" %d\r\n", A);
				printf("Input B:");
				scanf("%d", &B);
				printf(" %d\r\n", B);
				printf("Choose your operation ( 0:add  ,  1:sub  , 2:multiply )  :");
				scanf("%d", &C);
				printf(" %d\r\n", C);

				C_out = calculator(XPAR_CALCULATOR_0_S00_AXI_BASEADDR, A, B, C);

				printf("\r\nThe result of calculator is : %d\r\n\r\n",C_out);
				break;

			case 3:
				printf("Input A:");
				scanf("%d", &A);
				printf(" %d\r\n", A);

				P = parity(XPAR_PARITY_0_S00_AXI_BASEADDR, A);
				printf("\r\nA 's parity bit = %d\r\n\r\n", P);
				break;

			case 4:
				printf("Input a 4byte string: ");
				scanf("%s", &str);
				printf(" %s\r\n", str);

				int j;
				u32 str_to_bin = 0;
				for(j=0;j<4;j++){
					printf("char[%d] = %d\n" ,j,str[j]);
					int temp = str[j];
					printf("temp[%d] = %d\n" ,j,temp);
					str_to_bin =( temp << (j*8) ) + str_to_bin;
					printf("bin[%d] = %d\n" ,j,str_to_bin);
				}

				printf("wait for hash\n.\n.\n.\n.\n.\n");

				int H;
				H = hash(XPAR_DJB2_0_S00_AXI_BASEADDR,str_to_bin);
				printf("Result of hash function = %d\r\n\r\n" ,H);
				break;

			case 5:
				printf("Input reset:");
				scanf("%d", &reset);
				printf(" %d\r\n", reset);
				printf("Input R:");
				scanf("%d", &r);
				printf(" %d\r\n", r);
				printf("Input G:");
				scanf("%d", &g);
				printf(" %d\r\n", g);
				printf("Input B:");
				scanf("%d", &b);
				printf(" %d\r\n", b);

				pwm(XPAR_PWM_0_S00_AXI_BASEADDR,reset,r,g,b);

				printf("\r\nLook your LED!!\r\n\r\n");
				break;

			default:
				printf("\r\nwrong command\r\n\r\n");
		}

	}
	printf("Program End.\n\r");
    return 0;
}
