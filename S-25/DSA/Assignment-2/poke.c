#include <stdio.h>
#include <stdlib.h>

typedef struct PokeCardDex{
    int att;
    int def;
    int sum;
    int count;
    int children;
    struct PokeCardDex *left;
    struct PokeCardDex *right;
}Dex ;

Dex *root = NULL;
int cards = 0;
int kk=0;
int cards1=0;

Dex* KthStrongest(Dex *temp, int k) {
    temp = root;
    while (temp) {
        int right_size = temp->right ? temp->right->children + temp->right->count : 0;
        if (k > right_size && k <= right_size + temp->count) return temp;
        else
        if (k <= right_size) temp = temp->right;
        else if (k > right_size + temp->count  ) {
            k -= (right_size + temp->count);
            temp = temp->left;
        } else return temp;
    }
    return NULL;
}

// void kinorder(Dex *temp) {
//     if (temp == NULL || kk >= k) return;
//     kinorder(temp->right);
//     if (kk + temp->count >= k) {
//         if (kk < k) {
//             printf("%d %d %d\n", temp->att, temp->def, temp->count);
//             kk = k; 
//             //return;
//         }
//     }
//     else {
//         kk += temp->count;
//     }    
//     kinorder(temp->left);
// }

Dex *newNode(int att, int def){
    Dex *temp = (Dex *)malloc(sizeof(Dex));
    temp->att = att;
    temp->def = def;
    temp->sum = att + def;
    temp->count = 1;
    temp->children = 0;
    temp->left = temp->right = NULL;
    return temp;
}

void successor(Dex *temp,int att, int def){
    int hi=0;
    if(temp==NULL){
        //printf("0\n");
    }
    else{
        if(temp->right!=NULL){
            temp = temp->right;
            while(temp->left!=NULL){
                temp = temp->left;
            }
            printf("%d %d %d\n",temp->att,temp->def,temp->count);
            return ;
        }
    }
        Dex *succ = NULL;
        Dex *temp1 = root;
        while(temp1!=NULL){
            if(att+def==temp1->sum){
                if(att>temp1->att){
                    temp1 = temp1->right;
                }
                else if(att<temp1->att){
                    succ = temp1;
                    temp1 = temp1->left;
                    hi=1;
                }
                else{
                    break;
                }
            } else
            if(att+def<temp1->sum){
                succ = temp1;
                hi=1;
                temp1 = temp1->left;
            }
            else if(att+def>temp1->sum){
                temp1 = temp1->right;
            }
        }
        if(hi==1){
            printf("%d %d %d\n",succ->att,succ->def,succ->count);
        }
        else{
            printf("-1\n");
        }   
}

void predecessor(Dex *temp, int att, int def) {
    int hi = 0;
    if (temp == NULL) {
        //printf("0\n");
    } 
    else {
        if (temp->left != NULL) {
            temp = temp->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            printf("%d %d %d\n", temp->att, temp->def, temp->count);
            return;
        }
    }
        Dex *pred = NULL;
        Dex *temp1 = root;
        while (temp1 != NULL) {
            if (att + def == temp1->sum) {
                if (att < temp1->att) {
                    temp1 = temp1->left;
                } 
                else if (att > temp1->att) {
                    pred = temp1;
                    temp1 = temp1->right;
                    hi = 1;
                } 
                else {
                    break;
                }
            } 
            else if (att + def > temp1->sum) {
                pred = temp1;
                hi = 1;
                temp1 = temp1->right;
            } 
            else if (att + def < temp1->sum) {
                temp1 = temp1->left;
            }
        }
        if (hi == 1) {
            printf("%d %d %d\n", pred->att, pred->def, pred->count);
        } 
        else {
            printf("-1\n");
        }
}

// void insert(Dex *temp, int att, int def){
//     if(root == NULL){
//         root = newNode(att, def);
//         cards++;
//         return;
//     }
//     if(att==temp->att && def==temp->def){
//         temp->count++;
//         return;
//     }
//     if(att+def==temp->sum){
//         if(att>temp->att){
//             if(temp->right!=NULL){
//                 insert(temp->right,att,def);
//             }
//             else{
//                 temp->right = newNode(att,def);
//                 cards++;
//             }
//         }
//         else{
//             if(temp->left!=NULL){
//                 insert(temp->left,att,def);
//             }
//             else{
//                 temp->left = newNode(att,def);
//                 cards++;
//             }
//         }
//     }
//     else if(temp->sum > att + def){
//         if(temp->left != NULL){
//             insert(temp->left, att, def);
//         }else{
//             temp->left = newNode(att, def);
//             cards++;
//         }
//     }
//     else{
//         if(temp->right != NULL){
//             insert(temp->right, att, def);
//         }else{
//             temp->right = newNode(att, def);
//             cards++;
//         }
//     }
// }

void insert(Dex *temp,int att, int def) {
    if (root == NULL) {
        root = newNode(att, def);
        cards++;
        cards1++;
        return;
    }
    temp = root;
    while (1) {
        if (att == temp->att && def == temp->def) {
            temp->count++;
            cards1++;
            return;
        }
        if (att + def == temp->sum) {
            if (att > temp->att) {
                if (temp->right) {
                    temp->children++;
                    temp = temp->right;
                }
                else {
                    temp->children++;
                    temp->right = newNode(att, def);
                    cards++;
                    cards1++;
                    return;
                }
            } else {
                if (temp->left) {
                    temp->children++;
                    temp = temp->left;
                }
                else {
                    temp->children++;
                    temp->left = newNode(att, def);
                    cards++;
                    cards1++;
                    return;
                }
            }
        } else if (att + def < temp->sum) {
            if (temp->left) {
                temp->children++;
                temp = temp->left;
            }
            else {
                temp->children++;
                temp->left = newNode(att, def);
                cards++;
                cards1++;
                return;
            }
        } else {
            if (temp->right){
                temp->children++;
                temp = temp->right;
            }
            else {
                temp->children++;
                temp->right = newNode(att, def);
                cards++;
                cards1++;
                return;
            }
        }
    }
}

void decrease(Dex *temp, int att, int def) {
    temp = root;
    while (1) {
        if (att == temp->att && def == temp->def) {
            temp->count--;
            // cards1--;
            return;
        }
        temp->children--;
        if (att + def == temp->sum) {
            if (att > temp->att) temp = temp->right;
            else temp = temp->left;
        } else if (att + def < temp->sum) temp = temp->left;
        else temp = temp->right;
    }
}

void shu(int arr[][2], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp0 = arr[i][0], temp1 = arr[i][1];
        arr[i][0] = arr[j][0];
        arr[i][1] = arr[j][1];
        arr[j][0] = temp0;
        arr[j][1] = temp1;
    }
}

void notinorder(Dex *temp){
    if(temp==NULL){
        return;
    }
    notinorder(temp->right);
    printf("%d %d %d\n",temp->att,temp->def,temp->count);
    notinorder(temp->left);
}

Dex *isfound(Dex *root,int att, int def){
    Dex *temp = root;
    while (temp) {
        if (att == temp->att && def == temp->def) return temp;
        else if (att + def == temp->sum) temp = (att > temp->att) ? temp->right : temp->left;
        else temp = (att + def < temp->sum) ? temp->left : temp->right;
    }
    return NULL;
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n][2];
    for(int i = 0; i < n; i++){
        int att, def;
        scanf("%d %d", &att, &def);
        arr[i][0] = att;
        arr[i][1] = def;
    }
    rand();
    shu(arr,n);
    for(int i = 0; i < n; i++){
        int att, def;
        att = arr[i][0];
        def = arr[i][1];
        //scanf("%d %d", &att, &def);
        insert(root, att, def);
    }
    //notinorder(root);
    scanf("%d",&n);
    //printf("%d\n",n);
    char op[13];
    int q=n;
    int oa,od,ra,rd;
    for(int i=0;i<q;i++){
        scanf("%s", op);
        if(op[0]=='T' && op[1]=='R' && op[2]=='A' && op[3]=='D' && op[4]=='E'){
            scanf("%d %d %d %d",&oa,&od,&ra,&rd);
            if(oa==ra && od==rd){
                printf("0\n");
                continue;
            }
            if(ra==-1 && rd==-1){
                insert(root,oa,od);
                printf("1\n");
            }
            else {
                Dex *temp = isfound(root,ra,rd);
                int x = !temp?0:temp->count;
                if(x<=1){
                    printf("0\n");
                    continue;
                }
                else if(x>=2){
                    Dex *temp1 = isfound(root,oa,od);
                    int y = !temp1?0:temp1->count;
                    if(y<1){
                        //temp->count--;
                        decrease(root,ra,rd);
                        cards1--;
                        insert(root,oa,od);//
                        printf("1\n");
                    }
                    else{
                        if(temp1->att+temp1->def>temp->att+temp->def){
                            //temp->count--;
                            decrease(root,ra,rd);
                            insert(root,oa,od);
                            cards1--;
                            //temp1->count++;
                            printf("1\n");
                        }
                        else if(temp1->att+temp1->def==temp->att+temp->def){
                            if(temp1->att>temp->att){
                                //temp->count--;
                                //temp1->count++;
                                cards1--;
                                decrease(root,ra,rd);
                                insert(root,oa,od);
                                printf("1\n");
                            }
                            else{
                                printf("0\n");
                                continue;
                            }
                        }
                        else{
                            printf("0\n");
                        }
                    }   
                }
            }
        }
        else if(op[0]=='C' && op[1]=='O' && op[2]=='M' && op[3]=='P' && op[4]=='A' && op[5]=='R' && op[6]=='E'){
            int a,b;
            scanf("%d %d",&a,&b);
            Dex *temp = isfound(root,a,b);
            if(temp==NULL){
                printf("0\n");
            }
            else{
                printf("%d\n",temp->count);
            }
            predecessor(temp,a,b);
            successor(temp,a,b);
        }
        else if(op[0]=='K' && op[1]=='T' && op[2]=='H' && op[3]=='_' && op[4]=='S' && op[5]=='T' && op[6]=='R' && op[7]=='O' && op[8]=='N' && op[9]=='G' && op[10]=='E' && op[11]=='S' && op[12]=='T'){
            int k;
            scanf("%d",&k);
            kk=0;
            if(root==NULL){
                printf("-1\n");
                continue;
            }
            //printf("%d %d\n",cards1,k);
            if(k>cards1){
                printf("-1\n");
                continue;
            }
            Dex* temp = KthStrongest(root,k);
            if(temp) printf("%d %d %d\n",temp->att,temp->def,temp->count);
            //else printf("-1\n");
            //kinorder(root);
            //printf("%d\n",n);
        }
    }
    printf("%d\n",cards);
    notinorder(root);
    return 0;
}