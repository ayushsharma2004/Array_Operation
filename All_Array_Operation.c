#include<stdio.h>

int del(int *arr,int u_size,int loc);
void getArr(int *arr, int u_size) {
	int i, num;
	printf("Enter %d elements:-\n", u_size);
	for(i = 0; i < u_size; i++) {
		scanf("%d", &num);
		arr[i] = num;
	}
}
void sort_arr(int *arr, int n) {
	int i, j, m, temp;
	m = n;
	for(i = 0; i < n-1; i++) {
		for(j = i+1; j < n; j++) {
			if(arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		m--;
	}
}
void putArr(int *arr, int u_size) {
	int i;
	printf("The Array:-\n");
	for(i = 0; i < u_size; i++) {
		printf("%d\n", arr[i]);
	}
}
int ins(int *arr,int t_size, int u_size, int num) {
	int i, temp;
	temp = u_size;
	if (u_size >= t_size) {
		printf("Array is full!\n");
		return 0;
	}
	for(i = 0; i < u_size + 1; i++) {
		if(num < arr[temp - 1]) {
			arr[temp] = arr[temp-1];
			temp--;
		}
		else {
			arr[temp] = num;
			return 1;
		}
	}
	return 0;
}
int b_search(int *arr, int u_size, int d_num) {
	int i, fr, end, mid, temp, x;
	fr = 0; end = u_size - 1;
	mid = (fr + end)/2;
	temp = u_size-1;
	if(u_size == 0) {
		printf("Array is empty!");
		return -1;
	}
	if(arr[fr] == d_num) {
		x = del(arr, u_size, fr);
		return x;
	}
	if(arr[end] == d_num) {
		x = del(arr, u_size, end);
		return x;
	}
	while (mid >= fr) {
		if(arr[mid] == d_num) {
			x = del(arr, u_size, mid);
			return x;
		}
		if(arr[mid] < d_num) {
			fr = mid + 1;
		}
		if(arr[mid] > d_num) {
			end = mid - 1;
		}
		mid = (fr + end)/2;
	}
	return -1;
}
int del(int *arr,int u_size,int loc) {
	int i, temp;
	temp = u_size - loc - 1;
	for(int i = 0; i < temp; i++) {
		arr[loc] = arr[loc + 1];
		loc++;
	}
	return 2;
}
void check(int k, int *u) {
	switch(k) {
		case 0:
		  printf("Element Not Inserted!\n");
		  break;
		case 1:
		 printf("Element Inserted!\n");
		  *u = *u + 1;
		  break;
		case -1:
		  printf("Element Not Deleted!\n");
		  break;
		case 2:
		 printf("Element Deleted!\n");
		  *u = *u - 1;
		  break;
		default:
		 printf("Error!\n");
		 break;
	}
}

void main() {
	int t_size, u_size, num, op_sel, sel, d_num, ki, kd;
	printf("Enter the total size of the array:\n");
	scanf("%d", &t_size);
	int arr[t_size];
	printf("Enter the number of elements to be entered;\n");
	scanf("%d", &u_size);
	getArr(arr, u_size);
	sort_arr(arr, u_size);
	putArr(arr, u_size);
	do {
		sel = 0; 
		printf("Choose your operation:\n1:Insert\n2:Delete\n3:Display\n");
		scanf("%d", &op_sel);
		switch(op_sel) {
			case 1:
			  printf("Enter the number to be inserted:\n");
			  scanf("%d", &num);
			  ki = ins(arr, t_size, u_size, num);
			  check(ki, &u_size);
			  putArr(arr, u_size);
			  break;
			case 2:
			  printf("Enter the number to be deleted:\n");
			  scanf("%d", &d_num);
			  kd = b_search(arr, u_size, d_num);
			  check(kd, &u_size);
			  putArr(arr, u_size);
			  break;
			case 3:
			  putArr(arr, u_size);
			  break;
		}
		printf("Do you wanna continue:\n1: Yes\n2: No\n");
		scanf("%d", &sel);
	} while(sel == 1);
}