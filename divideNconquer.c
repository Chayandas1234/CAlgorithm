#include "divideNconquer.h"
//n : �߸� ���簢���� ũ��
//*start ������
//**array ��ü ���簢��
//*result ����� ���� �迭
void conqure(int n, int xStart, int yStart, int** array, int* result) {
    //�������� Ÿ�ϻ�
    int sColor = *(*(array + yStart) + xStart);
    //������ ������ �Ǻ� �÷���
    int isSameColor = 0;
    //1��Ž��(������)�̸� �ش�Ÿ���� ���� + 1 �� �� Ž�� ����
    if (n == 1) {
        *(result + sColor) += 1;
        return;
    }
    //y������ ���� n ��
    for (int i = yStart; i < yStart + n; i++) {
        //x������ ���� n�� Ž���ϸ鼭 ��� ������ Ÿ������ Ȯ��
        for (int j = xStart; j < xStart + n; j++) {
            //�ϳ��� ���� �ٸ���
            if (sColor != *(*(array + i) + j)) {
                //�Ǻ� �÷��׸� 1�� �ٲٰ�
                isSameColor = 1;
                //Ž�� ����
                break;
            }
        }
        //�Ǻ� �÷��װ� 1�̸� ���̻� Ž������ �ʰ� ����
        if (isSameColor == 1) break;
    }
    //Ž���� Ÿ���� ��� ���� ���̸�
    if (isSameColor == 0) {
        //�ش� Ÿ�ϻ��� +1 �ϰ� Ž�� ����
        *(result + sColor) += 1;
    }
    //������ Ÿ�ϻ��� �ϳ��� �ٸ���
    else {
        //�ش翵�� ����Ž��
        int nSize = n / 2;
        //�ϻ�и鿡�� n/2 ��ŭ
        conqure(nSize, xStart, yStart, array, result);
        //�̻�и鿡�� n/2 ��ŭ
        conqure(nSize, xStart + nSize, yStart, array, result);
        //���и鿡�� n/2��ŭ
        conqure(nSize, xStart, yStart + nSize, array, result);
        //���и鿡�� n/2��ŭ
        conqure(nSize, xStart + nSize, yStart + nSize, array, result);
    }
}

//n : ���簢���� ���μ��� ����
void solve2630(){
    int n = 0;
    scanf("%d", &n);
    //���簢�� �ʱ�ȭ
    int** array = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        *(array + i) = (int*)malloc(sizeof(int) * n);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", *(array + i) + j);
        }
    }
    int* result = (int*)malloc(sizeof(int) * 2);
    *(result + 0) = 0;
    *(result + 1) = 0;
    conqure(n, 0, 0, array, result);
    printf("%d\n", *(result + 0));
    printf("%d\n", *(result + 1));

}