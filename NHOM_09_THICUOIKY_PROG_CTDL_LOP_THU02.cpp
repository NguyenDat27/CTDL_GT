	#include <stdio.h>
#include <malloc.h>
#include <string.h>
struct Value
{
    char MMH[5];
    int DiemMH;
};
struct List
{
    Value GT;
    List *Next;
};
struct HocVien
{
    char Maso[9];
    char Hoten[31];
    char MMH1[5];
    int DM1;
    char MMH2[5];
    int DM2;
    List *link;
};
struct NODE
{
    HocVien data;
    NODE *left, *right, *parent;
};
int Xoa_vung_nho_tam()
{
    char temp;
    scanf("%c", &temp);
    if (temp == '\n')
        return 0;
    while (temp != '\n')
    {
        scanf("%c", &temp);
    }
    return 1;
}
void Nhap_diem_so(int &kq)
{
    do
    {
        printf("Nhap diem so: ");
        scanf("%d", &kq);
        while (Xoa_vung_nho_tam() == 1)
        {
            printf("Chi nhap vao so nguyen!\n");
            printf("Nhap diem so: ");
            scanf("%d", &kq);
        }
        if (kq >= 0 && kq <= 10)
            break;
        else
            printf("Diem so chi trong pham vi tu 0 den 10\n");
    } while (1);
}
int KT_khoang_trang(char A[])
{
    int i = 0;
    while (A[i] != '\0')
    {
        if (A[i] == ' ')
            return 1;
        i = i + 1;
    }
    return 0;
}
void Nhapdethoat()
{
    char c;
    printf("\nNhan ENTER de tiep tuc\n");
    scanf("%c", &c);
    while (c != '\n')
    {
        Xoa_vung_nho_tam();
        printf("\nNhan ENTER de tiep tuc\n");
        scanf("%c", &c);
    }
}
int Xoa_Xuong_Dong(char A[])
{
    int length;
    length = strlen(A);
    if (A[length - 1] == '\n')
    {
        A[length - 1] = '\0';
        return 1;
    }
    return 0;
}
int Duyet_KT_list(List *T, char A[])
{
    List *p;
    p = NULL;
    p = T;
    while (p != NULL)
    {
        if (strcmp((p->GT.MMH), A) == 0)
            return p->GT.DiemMH;
        p = p->Next;
    }
    return -1;
}
NODE *Tim_kiem(NODE *T, char MS[])
{
    while ((T != NULL) && (strcmp(MS, T->data.Maso) != 0))
    {
        if (strcmp(MS, T->data.Maso) < 0)
            T = T->left;
        else
            T = T->right;
    }
    return T;
}
void Duyet_LNR_1(NODE *x)
{
    if (x != NULL)
    {
        Duyet_LNR_1(x->left);
        printf("  %-17s%-30s%7d\n",
               x->data.Maso, x->data.Hoten, x->data.DM1);
        Duyet_LNR_1(x->right);
    }
}
void Duyet_LNR_2(NODE *x)
{
    if (x != NULL)
    {
        Duyet_LNR_2(x->left);
        printf("  %-17s%-30s%7d\n",
               x->data.Maso, x->data.Hoten, x->data.DM2);
        Duyet_LNR_2(x->right);
    }
}
void Duyet_LNR_3(NODE *x)
{
    if (x != NULL)
    {
        Duyet_LNR_3(x->left);
        printf("  %-17s%-30s%7d%15d\n",
               x->data.Maso, x->data.Hoten, x->data.DM1, x->data.DM2);
        Duyet_LNR_3(x->right);
    }
}
void AddSV(NODE *&T, HocVien X)
{
    NODE *y, *z, *p;
    z = NULL;
    p = NULL;
    p = (NODE *)malloc(sizeof(NODE));
    if (p == NULL)
    {
        printf("Co loi! khong the cap phat bo nho.\n");
        return;
    }
    p->data = X;
    p->left = NULL;
    p->parent = NULL;
    p->right = NULL;
    y = NULL;
    z = T;
    while (z != NULL)
    {
        y = z;
        if (strcmp(p->data.Maso, z->data.Maso) < 0)
            z = z->left;
        else
            z = z->right;
    }
    p->parent = y;
    if (y == NULL)
    {
        T = p;
    }
    else
    {
        if (strcmp(p->data.Maso, y->data.Maso) < 0)
        {
            y->left = p;
        }
        else
            y->right = p;
    }
}
void Them_vao_List(NODE *T)
{
    List *p;
    p = NULL;
    p = (List *)malloc(sizeof(List));
    if (p == NULL)
    {
        printf("Co loi! khong the cap phat bo nho.\n");
        return;
    }
    p->Next = NULL;
    printf("Nhap ma mon hoc phu: ");
    fgets(p->GT.MMH, sizeof(p->GT.MMH), stdin);
    while (Xoa_Xuong_Dong(p->GT.MMH) == 1 || Xoa_vung_nho_tam() == 1)
    {
        printf("Nhap dung 4 ki tu!!!\n");
        printf("Nhap ma mon hoc phu: ");
        fgets(p->GT.MMH, sizeof(p->GT.MMH), stdin);
    }
    while (Duyet_KT_list((T->data.link), (p->GT.MMH)) != -1 || strcmp((T->data.MMH1), (p->GT.MMH)) == 0 || strcmp((T->data.MMH2), (p->GT.MMH)) == 0)
    {
        printf("Da co ma mon hoc nay!!!\n");
        printf("Nhap lai ma mon hoc phu: ");
        fgets(p->GT.MMH, sizeof(p->GT.MMH), stdin);
        while (Xoa_Xuong_Dong(p->GT.MMH) == 1 || Xoa_vung_nho_tam() == 1)
        {
            printf("Nhap dung 4 ki tu!!!\n");
            printf("Nhap ma mon hoc phu: ");
            fgets(p->GT.MMH, sizeof(p->GT.MMH), stdin);
        }
    }
    Nhap_diem_so(p->GT.DiemMH);
    p->Next = T->data.link;
    T->data.link = p;
}
void NhapSV(HocVien &A)
{
    printf("Nhap ho ten: ");
    fgets(A.Hoten, sizeof(A.Hoten), stdin);
    while (Xoa_Xuong_Dong(A.Hoten) == 0 && Xoa_vung_nho_tam() == 1)
    {
        printf("Nhap ho ten tu 30 ki tu tro xuong!!!\n");
        printf("Nhap ho ten: ");
        fgets(A.Hoten, sizeof(A.Hoten), stdin);
    }
    printf("Nhap ma mon hoc 1: ");
    fgets(A.MMH1, sizeof(A.MMH1), stdin);
    while (Xoa_Xuong_Dong(A.MMH1) == 1 || Xoa_vung_nho_tam() == 1)
    {
        printf("Nhap dung 4 ki tu!!!\n");
        printf("Nhap ma mon hoc 1: ");
        fgets(A.MMH1, sizeof(A.MMH1), stdin);
    }
    Nhap_diem_so(A.DM1);
    printf("Nhap ma mon hoc 2: ");
    fgets(A.MMH2, sizeof(A.MMH2), stdin);
    while (Xoa_Xuong_Dong(A.MMH2) == 1 || Xoa_vung_nho_tam() == 1)
    {
        printf("Nhap dung 4 ki tu!!!\n");
        printf("Nhap ma mon hoc 2: ");
        fgets(A.MMH2, sizeof(A.MMH2), stdin);
    }
    while (strcmp(A.MMH2, A.MMH1) == 0)
    {
        printf("Trung ma mon hoc 1!!!\n");
        printf("Nhap lai ma mon hoc 2: ");
        fgets(A.MMH2, sizeof(A.MMH2), stdin);
        while (Xoa_Xuong_Dong(A.MMH2) == 1 || Xoa_vung_nho_tam() == 1)
        {
            printf("Nhap dung 4 ki tu!!!\n");
            printf("Nhap ma mon hoc 2: ");
            fgets(A.MMH2, sizeof(A.MMH2), stdin);
        }
    }
    Nhap_diem_so(A.DM2);
    A.link = NULL;
}
void Them_hoc_vien(NODE *&T)
{
    HocVien A;
    int check;
    check = 1;
    do
    {
        if (check == 1)
        {
            do
            {
                printf("Nhap ma so hoc vien: ");
                fgets(A.Maso, sizeof(A.Maso), stdin);
                if (Xoa_Xuong_Dong(A.Maso) == 1 || Xoa_vung_nho_tam() == 1)
                {
                    printf("Nhap dung 8 ki tu!!!\n");
                }
                else
                {
                    if (KT_khoang_trang(A.Maso) == 0)
                        break;
                    else
                        printf("Khong duoc nhap khoang trang!!!\n");
                }
            } while (1);
            if (Tim_kiem(T, A.Maso) != NULL)
                check = 0;
            else
                break;
        }
        else
        {
            printf("!!!Da co hoc vien co ma so %s\n", A.Maso);
            printf("Nhap lai:\n");
            check = 1;
        }
    } while (1);
    NhapSV(A);
    AddSV(T, A);
}
void Them_HP(NODE *T)
{
    char A[9];
    NODE *kq;
    do
    {
        printf("Nhap ma so hoc vien: ");
        fgets(A, sizeof(A), stdin);
        if (Xoa_Xuong_Dong(A) == 1 || Xoa_vung_nho_tam() == 1)
        {
            printf("Nhap dung 8 ki tu!!!\n");
        }
        else
        {
            if (KT_khoang_trang(A) == 0)
                break;
            else
                printf("Khong duoc nhap khoang trang!!!\n");
        }
    } while (1);
    kq = Tim_kiem(T, A);
    if (kq != NULL)
    {
        Them_vao_List(kq);
    }
    else
        printf("Khong co hoc vien trong BST!!!\n");
}
void Inthongtin_theoMHV(NODE *T)
{
    NODE *kq;
    kq = NULL;
    char Key[9];
    do
    {
        printf("Nhap ma so hoc vien: ");
        fgets(Key, sizeof(Key), stdin);
        if (Xoa_Xuong_Dong(Key) == 1 || Xoa_vung_nho_tam() == 1)
        {
            printf("Nhap dung 8 ki tu!!!\n");
        }
        else
        {
            if (KT_khoang_trang(Key) == 0)
                break;
            else
                printf("Khong duoc nhap khoang trang!!!\n");
        }
    } while (1);
    kq = Tim_kiem(T, Key);
    printf("Ket qua:\n");
    if (kq != NULL)
    {
        printf("\n%-30s%14s%15s\n", "Ho ten hoc vien", "Diem mon 1", "Diem mon 2");
        printf("%-30s%9d%15d\n", kq->data.Hoten, kq->data.DM1, kq->data.DM2);
    }
    else
        printf("Khong tim thay ma so hoc vien %s\n", Key);
}
NODE *Trai_nhat(NODE *x)
{
    while (x->left != NULL)
    {
        x = x->left;
    }
    return x;
}
NODE *Xoa_node(NODE *&ROOT, NODE *T)
{
    NODE *x, *y;
    if (T->left == NULL || T->right == NULL)
    {
        y = T;
    }
    else
        y = Trai_nhat(T->right);
    if (y->left != NULL)
        x = y->left;
    else
        x = y->right;
    if (x != NULL)
    {
        x->parent = y->parent;
    }
    if (y->parent == NULL)
        ROOT = x;
    else
    {
        if (y == (y->parent)->left)
            (y->parent)->left = x;
        else
            (y->parent)->right = x;
    }
    if (y != T)
    {
        T->data = y->data;
    }
    return y;
}
void Goi_xoa(NODE *&T)
{
    char A[9];
    NODE *kq;
    List *temp;
    temp = NULL;
    kq = NULL;
    do
    {
        printf("Nhap ma so hoc vien: ");
        fgets(A, sizeof(A), stdin);
        if (Xoa_Xuong_Dong(A) == 1 || Xoa_vung_nho_tam() == 1)
        {
            printf("Nhap dung 8 ki tu!!!\n");
        }
        else
        {
            if (KT_khoang_trang(A) == 0)
                break;
            else
                printf("Khong duoc nhap khoang trang!!!\n");
        }
    } while (1);
    kq = Tim_kiem(T, A);
    if (kq != NULL)
    {
        kq = Xoa_node(T, kq);
        while (kq->data.link != NULL)
        {
            temp = kq->data.link;
            kq->data.link = (kq->data.link)->Next;
            free(temp);
        }
        free(kq);
        printf("Da xoa\n");
    }
    else
        printf("Khong co hoc vien trong BST!!!\n");
}
void AddSVMH1(NODE *&T, HocVien X)
{
    NODE *y, *z, *p;
    z = NULL;
    p = NULL;
    p = (NODE *)malloc(sizeof(NODE));
    if (p == NULL)
    {
        printf("Co loi! khong the cap phat bo nho.\n");
        return;
    }
    p->data = X;
    p->left = NULL;
    p->parent = NULL;
    p->right = NULL;
    y = NULL;
    z = T;
    while (z != NULL)
    {
        y = z;
        if (p->data.DM1 < z->data.DM1)
            z = z->left;
        else
            z = z->right;
    }
    p->parent = y;
    if (y == NULL)
    {
        T = p;
    }
    else
    {
        if (p->data.DM1 < y->data.DM1)
        {
            y->left = p;
        }
        else
            y->right = p;
    }
}
void Duyet_NLR_1(NODE *x, NODE *&T1)
{
    if (x != NULL)
    {
        AddSVMH1(T1, (x->data));
        Duyet_NLR_1(x->left, T1);
        Duyet_NLR_1(x->right, T1);
    }
}
void Tang_dan_DM1(NODE *T)
{
    NODE *T1;
    T1 = NULL;
    Duyet_NLR_1(T, T1);
    printf("%-19s%-32s%s\n", "Ma so hoc vien", "Ho ten hoc vien", "Diem mon 1");
    Duyet_LNR_1(T1);
}
void AddSVMH2(NODE *&T, HocVien X)
{
    NODE *y, *z, *p;
    p = NULL;
    z = NULL;
    p = (NODE *)malloc(sizeof(NODE));
    if (p == NULL)
    {
        printf("Co loi! khong the cap phat bo nho.\n");
        return;
    }
    p->data = X;
    p->left = NULL;
    p->parent = NULL;
    p->right = NULL;
    y = NULL;
    z = T;
    while (z != NULL)
    {
        y = z;
        if (p->data.DM2 < z->data.DM2)
            z = z->left;
        else
            z = z->right;
    }
    p->parent = y;
    if (y == NULL)
    {
        T = p;
    }
    else
    {
        if (p->data.DM2 < y->data.DM2)
        {
            y->left = p;
        }
        else
            y->right = p;
    }
}
void Duyet_NLR_2(NODE *x, NODE *&T1)
{
    if (x != NULL)
    {
        AddSVMH2(T1, (x->data));
        Duyet_NLR_2(x->left, T1);
        Duyet_NLR_2(x->right, T1);
    }
}
void Tang_dan_DM2(NODE *T)
{
    NODE *T1;
    T1 = NULL;
    Duyet_NLR_2(T, T1);
    printf("%-19s%-32s%s\n", "Ma so hoc vien", "Ho ten hoc vien", "Diem mon 2");
    Duyet_LNR_2(T1);
}
int sosanh(NODE *x, NODE *y)
{
    if (x->data.DM1 != y->data.DM1)
    {
        if (x->data.DM1 < y->data.DM1)
            return 1;
        else
            return 0;
    }
    else
    {
        if (x->data.DM2 < y->data.DM2)
            return 1;
        else
            return 0;
    }
}
void AddSVMH_1_2(NODE *&T, HocVien X)
{
    NODE *y, *z, *p;
    z = NULL;
    p = NULL;
    p = (NODE *)malloc(sizeof(NODE));
    if (p == NULL)
    {
        printf("Co loi! khong the cap phat bo nho.\n");
        return;
    }
    p->data = X;
    p->left = NULL;
    p->parent = NULL;
    p->right = NULL;
    y = NULL;
    z = T;
    while (z != NULL)
    {
        y = z;
        if (sosanh(p, z) == 1)
            z = z->left;
        else
            z = z->right;
    }
    p->parent = y;
    if (y == NULL)
    {
        T = p;
    }
    else
    {
        if (sosanh(p, y) == 1)
        {
            y->left = p;
        }
        else
            y->right = p;
    }
}
void Duyet_NLR_3(NODE *x, NODE *&T1)
{
    if (x != NULL)
    {
        AddSVMH_1_2(T1, (x->data));
        Duyet_NLR_3(x->left, T1);
        Duyet_NLR_3(x->right, T1);
    }
}
void Tang_dan_DM1_DM2(NODE *T)
{
    NODE *T1;
    T1 = NULL;
    Duyet_NLR_3(T, T1);
    printf("%-19s%-32s%s%15s\n", "Ma so hoc vien", "Ho ten hoc vien", "Diem mon 1", "Diem mon 2");
    Duyet_LNR_3(T1);
}
void Duyet_inthongtin(NODE *T, char A[], char &check)
{
    if (T != NULL)
    {
        if (strcmp((T->data.MMH1), A) == 0)
        {
            printf("%-30s%10d\n", T->data.Hoten, T->data.DM1);
            check = '1';
        }
        else if (strcmp((T->data.MMH2), A) == 0)
        {
            printf("%-30s%10d\n", T->data.Hoten, T->data.DM2);
            check = '1';
        }
        else
        {
            int kq;
            kq = Duyet_KT_list(T->data.link, A);
            if (kq != -1)
            {
                printf("%-30s%10d\n", T->data.Hoten, kq);
                check = '1';
            }
        }
        Duyet_inthongtin(T->left, A, check);
        Duyet_inthongtin(T->right, A, check);
    }
}
void Inthongtin_theoMMH(NODE *T)
{
    char temp[5], kq;
    kq = '0';
    printf("Nhap ma mon hoc: ");
    fgets(temp, sizeof(temp), stdin);
    while (Xoa_Xuong_Dong(temp) == 1 || Xoa_vung_nho_tam() == 1)
    {
        printf("Nhap dung 4 ki tu!!!\n");
        printf("Nhap lai ma mon hoc: ");
        fgets(temp, sizeof(temp), stdin);
    }
    printf("Ket qua:\n");
    printf("%-30s%12s\n", "Ho ten hoc vien", "Diem so");
    Duyet_inthongtin(T, temp, kq);
    if (kq == '0')
        printf("Khong tim thay ma mon hoc nay!!!\n");
}
void Viet_NLR(NODE *T)
{
    if (T != NULL)
    {
        if (T->parent == NULL)
            printf("%s %s, %s\n", T->data.Maso, T->data.Hoten, "Root");
        else
        {
            if (T == (T->parent)->left)
                printf("%s %s, %s %s %s\n", T->data.Maso, T->data.Hoten, "nut con trai cua", (T->parent)->data.Maso, (T->parent)->data.Hoten);
            else
                printf("%s %s, %s %s %s\n", T->data.Maso, T->data.Hoten, "nut con phai cua", (T->parent)->data.Maso, (T->parent)->data.Hoten);
        }
        Viet_NLR(T->left);
        Viet_NLR(T->right);
    }
}
void Ghi_dat(NODE *T, FILE *f)
{
    char temp = '\n';
    if (T != NULL)
    {
        fwrite(T->data.Maso, sizeof(T->data.Maso), 1, f);
        fwrite(T->data.Hoten, sizeof(T->data.Hoten), 1, f);
        fwrite(T->data.MMH1, sizeof(T->data.MMH1), 1, f);
        fwrite(&(T->data.DM1), sizeof(T->data.DM1), 1, f);
        fwrite(T->data.MMH2, sizeof(T->data.MMH2), 1, f);
        fwrite(&(T->data.DM2), sizeof(T->data.DM2), 1, f);
        while (T->data.link != NULL)
        {
            fwrite(T->data.link->GT.MMH, sizeof(T->data.link->GT.MMH), 1, f);
            fwrite(&(T->data.link->GT.DiemMH), sizeof(T->data.link->GT.DiemMH), 1, f);
            T->data.link = T->data.link->Next;
        }
        fwrite(&temp, sizeof(temp), 1, f);
        Ghi_dat(T->left, f);
        Ghi_dat(T->right, f);
    }
}
void Ghifile_dat(NODE *T)
{
    char Filename[261];
    printf("\nNhap vao duong dan va ten file: ");
    fgets(Filename, sizeof(Filename), stdin);
    while (Xoa_Xuong_Dong(Filename) == 0 && Xoa_vung_nho_tam() == 1)
    {
        printf("Nhap vao duong dan duoi 260 ki tu!!!\n");
        printf("Nhap vao duong dan va ten file: ");
        fgets(Filename, sizeof(Filename), stdin);
    }
    FILE *f;
    f = fopen(Filename, "wb");
    if (f == NULL)
    {
        printf("\nFile khong mo duoc de ghi!!!\n");
        return;
    }
    Ghi_dat(T, f);
    fclose(f);
    printf("Da ghi xong...\n");
}
void NewLIST(List *&T, Value A)
{
    List *p;
    p = NULL;
    p = (List *)malloc(sizeof(List));
    if (p == NULL)
    {
        printf("Co loi! khong the cap phat bo nho.\n");
        return;
    }
    p->Next = NULL;
    p->GT = A;
    if (T == NULL)
        T = p;
    else
    {
        p->Next = T;
        T = p;
    }
}
void Noi_chuoi(char MMH[], char temp)
{
    int i;
    for (i = 4; i > 0; i--)
    {
        MMH[i] = MMH[i - 1];
    }
    MMH[i] = temp;
}
void Mofile_dat()
{
    int chon;
    char temp;
    Value x;
    HocVien A;
    NODE *dx;
    char Filename[261];
    dx = NULL;
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("* Nhap 1: De nhap duong dan va ten file.                        *\n");
    printf("* Nhap 2: De mo duong dan mac dinh(D:\\\\DATACTDL\\\\hocvien.dat).  *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    do
    {
        printf("Nhap vao 1 so va nhan enter: ");
        scanf("%d", &chon);
        while (Xoa_vung_nho_tam() == 1)
        {
            printf("Chi nhap vao so!\n");
            printf("Nhap lai 1 so va nhan enter: ");
            scanf("%d", &chon);
        }
        if (chon != 1 && chon != 2)
            printf("Nhap 1 trong 2 so tren!!!\n");
        else
            break;
    } while (1);
    if (chon == 1)
    {
        printf("\nNhap vao duong dan va ten file: ");
        fgets(Filename, sizeof(Filename), stdin);
        while (Xoa_Xuong_Dong(Filename) == 0 && Xoa_vung_nho_tam() == 1)
        {
            printf("Nhap vao duong dan duoi 260 ki tu!!!\n");
            printf("Nhap vao duong dan va ten file: ");
            fgets(Filename, sizeof(Filename), stdin);
        }
    }
    else
    {
        char file[] = "D:\\DATACTDL\\hocvien.dat";
        strcpy(Filename, file);
    }
    FILE *f;
    f = fopen(Filename, "rb");
    if (f == NULL)
    {
        printf("\nFile khong mo duoc de doc!!!\n");
        Nhapdethoat();
        return;
    }
    while (fread(A.Maso, sizeof(A.Maso), 1, f) == 1)
    {
        fread(A.Hoten, sizeof(A.Hoten), 1, f);
        fread(A.MMH1, sizeof(A.MMH1), 1, f);
        fread(&(A.DM1), sizeof(A.DM1), 1, f);
        fread(A.MMH2, sizeof(A.MMH2), 1, f);
        fread(&(A.DM2), sizeof(A.DM2), 1, f);
        A.link = NULL;
        fread(&temp, sizeof(temp), 1, f);
        while (temp != '\n')
        {
            fread(x.MMH, sizeof(x.MMH) - 1, 1, f);
            Noi_chuoi(x.MMH, temp);
            fread(&(x.DiemMH), sizeof(x.DiemMH), 1, f);
            NewLIST(A.link, x);
            fread(&temp, sizeof(temp), 1, f);
        }
        AddSV(dx, A);
    }
    fclose(f);
    printf("Da mo xong...\n");
    Nhapdethoat();
    do
    {
        printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
        printf("*                          MENU MO FILE                         *\n");
        printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
        printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
        printf("*   1. Nhap 1 de in ra man hinh HTHV, DM1, DM2 theo MSHV.       *\n");
        printf("*   2. Nhap 2 de xoa hoc vien.                                  *\n");
        printf("*   3. Nhap 3 de in ra man hinh theo thu tu tang dan DM1.       *\n");
        printf("*   4. Nhap 4 de in ra man hinh theo thu tu tang dan DM2.       *\n");
        printf("*   5. Nhap 5 de in ra man hinh theo thu tu tang dan DM1, DM2.  *\n");
        printf("*   6. Nhap 6 de in ra man hinh HTHV, DMH theo MMH.             *\n");
        printf("*   7. Nhap 7 de viet ra man hinh MSHV, HTHV dang cay.          *\n");
        printf("*   8. Nhap 8 de ghi thong tin vao file.                        *\n");
        printf("*   9. Nhap 9 de thoat.                                         *\n");
        printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
        printf("Nhap vao 1 so nguyen va nhan enter: ");
        scanf("%d", &chon);
        while (Xoa_vung_nho_tam() == 1)
        {
            printf("Chi nhap vao so nguyen!\n");
            printf("Nhap lai 1 so nguyen va nhan enter: ");
            scanf("%d", &chon);
        }
        switch (chon)
        {
        case 1:
            printf("Da chon 1\n");
            Inthongtin_theoMHV(dx);
            Nhapdethoat();
            break;
        case 2:
            printf("Da chon 2\n");
            Goi_xoa(dx);
            Nhapdethoat();
            break;
        case 3:
            printf("Da chon 3\n");
            Tang_dan_DM1(dx);
            Nhapdethoat();
            break;
        case 4:
            printf("Da chon 4\n");
            Tang_dan_DM2(dx);
            Nhapdethoat();
            break;
        case 5:
            printf("Da chon 5\n");
            Tang_dan_DM1_DM2(dx);
            Nhapdethoat();
            break;
        case 6:
            printf("Da chon 6\n");
            Inthongtin_theoMMH(dx);
            Nhapdethoat();
            break;
        case 7:
            printf("Da chon 7\n");
            Viet_NLR(dx);
            Nhapdethoat();
            break;
        case 8:
            printf("Da chon 8\n");
            Ghifile_dat(dx);
            Nhapdethoat();
            break;
        case 9:
            printf("Da chon 9\n");
            printf("Thoat...\n");
            Nhapdethoat();
            break;
        default:
            break;
        }
        if (chon == 9)
            break;
    } while (1);
}

int main()
{
    NODE *dx;
    int chon;
    dx = NULL;
    do
    {
        printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
        printf("*                         MENU CHINH                            *\n");
        printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
        printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
        printf("*   1. Nhap 1 de them hoc vien moi.                             *\n");
        printf("*   2. Nhap 2 de them MHP theo MSHV.                            *\n");
        printf("*   3. Nhap 3 de in ra man hinh HTHV, DM1, DM2 theo MSHV.       *\n");
        printf("*   4. Nhap 4 de xoa hoc vien.                                  *\n");
        printf("*   5. Nhap 5 de in ra man hinh theo thu tu tang dan DM1.       *\n");
        printf("*   6. Nhap 6 de in ra man hinh theo thu tu tang dan DM2.       *\n");
        printf("*   7. Nhap 7 de in ra man hinh theo thu tu tang dan DM1, DM2.  *\n");
        printf("*   8. Nhap 8 de in ra man hinh HTHV, DMH theo MMH.             *\n");
        printf("*   9. Nhap 9 de viet ra man hinh MSHV, HTHV dang cay.          *\n");
        printf("*  10. Nhap 10 de ghi thong tin vao file.                       *\n");
        printf("*  11. Nhap 11 de mo file.                                      *\n");
        printf("*  12. Nhap 12 de thoat.                                        *\n");
        printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
        printf("Nhap vao 1 so nguyen va nhan enter: ");
        scanf("%d", &chon);
        while (Xoa_vung_nho_tam() == 1)
        {
            printf("Chi nhap vao so nguyen!\n");
            printf("Nhap lai 1 so nguyen va nhan enter: ");
            scanf("%d", &chon);
        }
        switch (chon)
        {
        case 1:
            printf("Da chon 1\n");
            Them_hoc_vien(dx);
            Nhapdethoat();
            break;
        case 2:
            printf("Da chon 2\n");
            Them_HP(dx);
            Nhapdethoat();
            break;
        case 3:
            printf("Da chon 3\n");
            Inthongtin_theoMHV(dx);
            Nhapdethoat();
            break;
        case 4:
            printf("Da chon 4\n");
            Goi_xoa(dx);
            Nhapdethoat();
            break;
        case 5:
            printf("Da chon 5\n");
            Tang_dan_DM1(dx);
            Nhapdethoat();
            break;
        case 6:
            printf("Da chon 6\n");
            Tang_dan_DM2(dx);
            Nhapdethoat();
            break;
        case 7:
            printf("Da chon 7\n");
            Tang_dan_DM1_DM2(dx);
            Nhapdethoat();
            break;
        case 8:
            printf("Da chon 8\n");
            Inthongtin_theoMMH(dx);
            Nhapdethoat();
            break;
        case 9:
            printf("Da chon 9\n");
            Viet_NLR(dx);
            Nhapdethoat();
            break;
        case 10:
            printf("Da chon 10\n");
            Ghifile_dat(dx);
            Nhapdethoat();
            break;
        case 11:
            printf("Da chon 11\n");
            Mofile_dat();
            break;
        case 12:
            printf("Da chon 12\n");
            printf("Thoat...\n");
            break;
        default:
            break;
        }
        if (chon == 12)
            break;
    } while (1);
    return 0;
}
