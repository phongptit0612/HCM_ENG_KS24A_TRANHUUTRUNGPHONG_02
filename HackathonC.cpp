#include <stdio.h>
int main() {
    int choice, arr[100], n = 0, position, target;

    while (1) {
    	printf("=====MENU=====");
        printf("\n1. Nhap so phan tu va gia tri cho mang.\n");
        printf("2. In ra gia tri cac phan tu trong mang.\n");
        printf("3. Dem so luong cac phan tu trong mang.\n");
        printf("4. Tim gia tri lon thu hai trong mang.\n");
        printf("5. Them mot phan tu vao dau mang, nguoi dung nhap.\n");
        printf("6. Xoa phan tu tai vi tri cu the, nguoi dung nhap vi tri.\n");
        printf("7. Sap xep theo thu tu giam dan (Insertion sort).\n");
        printf("8. Nhap vao mot phan tu, tiem kiem phan tu co ton tai hay khong (Binary search).\n");
        printf("9. In ra toan bo so nguyen to trong mang.\n");
        printf("10. Sap xep theo thu tu giam dan (Bubble sort).\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Nhap so luong phan tu (1 - 100): ");
                scanf("%d", &n);
                if (n > 100 || n < 1) {
                printf("So luong phan tu phai nam trong khoang (1 - 100)\n");
                break;
                }

                for (int i = 0; i < n; i++) {
                printf("Nhap phan tu [%d]: ", i + 1);
                scanf("%d", &arr[i]);
                }
                break;
            }

            case 2: {
                if (n == 0) {
                printf("Mang rong.\n");
                break;
                }

                printf("Cac phan tu trong mang: ");
                for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }

            case 3: {
                printf("So luong phan tu trong mang: %d\n", n);
                break;
            }

            case 4: {
                if (n < 2) {
                    printf("Mang phai co it nhat 2 phan tu.\n");
                    break;
                }

                int largest = arr[0], second = arr[0];
                for (int i = 1; i < n; i++) {
                if (arr[i] > largest) {
                        second = largest;
                        largest = arr[i];
                    } else if (arr[i] > second && arr[i] != largest) {
                        second = arr[i];
                    }
                }

                if (second == largest) {
                    printf("Khong ton tai gia tri lon thu hai.\n");
                } else {
                    printf("Gia tri lon thu hai trong mang: %d\n", second);
                }
                break;
            }

            case 5: {
            	int value;
                printf("Nhap gia tri can them vao dau mang: ");
                scanf("%d", &value);
                if (n >= 100) {
                    printf("Mang da day!\n");
                    break;
                }

                for (int i = n; i > 0; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[0] = value;
                n++;
                break;
            }

            case 6: {
                printf("Nhap vi tri can xoa (0 - %d): ", n - 1);
                scanf("%d", &position);

                if (position < 0 || position >= n) {
                    printf("Vi tri khong hop le.\n");
                    break;
                }

                for (int i = position; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                break;
            }

            case 7: {
                for (int i = 1; i < n; i++) {
                int numb = arr[i];
                int j = i - 1;
                while (j >= 0 && arr[j] < numb) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = numb;
                }
                printf("Mang sau khi sap xep theo thu tu giam dan (Insertion Sort):\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }

            case 8: {
                printf("Nhap gia tri can tim: ");
                scanf("%d", &target);

                int low = 0, high = n - 1, found = 0;
                while (low <= high) {
                int mid = (low + high) / 2;
                if (arr[mid] == target) {
                        found = 1;
                        break;
                    } else if (arr[mid] < target) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }

                if (found) {
                    printf("Phan tu %d co ton tai trong mang.\n", target);
                } else {
                    printf("Phan tu %d khong ton tai trong mang.\n", target);
                }
                break;
            }

            case 9: {
                int foundPrime = 0;
                for (int i = 0; i < n; i++) {
                int num = arr[i];
                
                if (num >= 2) {
                int isPrime = 1;
                for (int j = 2; j * j <= num; j++) {
                if (num % j == 0) {
                    isPrime = 0;
                    break;
                }
            }

                if (isPrime) {
                printf("%d ", num);
                foundPrime = 1;
            }
        }
    }

    if (!foundPrime) {
        printf("Mang khong co so nguyen to.\n");
    } else {
        printf("\n");
    }

    break;
}
            case 10: {
                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - 1 - i; j++) {
                        if (arr[j] < arr[j + 1]) {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Mang sau khi sap xep theo thu tu giam dan (Bubble Sort):\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }

            default:
                printf("Lua chon khong hop le, nhap lai.\n");
        }
    }

    return 0;
}

