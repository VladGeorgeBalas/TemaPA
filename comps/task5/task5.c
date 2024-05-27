#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../libs/list/list.h"
#include "../../libs/tree/tree.h"
#include "../../libs/data/data.h"

extern float tem_pts(struct team *_tem);

struct list_node *add_avl_nod(struct list_node *rtt, struct team *tem) {
    fprintf(stderr, "-->%s\n", ((struct team *) ((struct bee_tre_nod *) rtt->next)->val)->name);
    if (tem_pts((struct team *) ((struct bee_tre_nod *) rtt->next)->val) > tem_pts(tem)) {
        if (((struct bee_tre_nod *) rtt->next)->rht)
            return add_avl_nod((struct list_node *) ((struct bee_tre_nod *) rtt->next)->rht, tem);
        else {
            ((struct bee_tre_nod *) rtt->next)->rht = malloc(sizeof(struct list_node));
            struct list_node *res = ((struct list_node *) ((struct bee_tre_nod *) rtt->next)->rht);
            res->next = malloc(sizeof(struct bee_tre_nod));
            ((struct bee_tre_nod *) res->next)->val = tem;
            ((struct bee_tre_nod *) res->next)->rht = NULL;
            ((struct bee_tre_nod *) res->next)->lft = NULL;

            return res;
        }
    } else {
        if (((struct bee_tre_nod *) rtt->next)->lft)
            return add_avl_nod((struct list_node *) ((struct bee_tre_nod *) rtt->next)->lft, tem);
        else {
            ((struct bee_tre_nod *) rtt->next)->lft = malloc(sizeof(struct list_node));
            struct list_node *res = ((struct list_node *) ((struct bee_tre_nod *) rtt->next)->lft);
            res->next = malloc(sizeof(struct bee_tre_nod));
            ((struct bee_tre_nod *) res->next)->val = tem;
            ((struct bee_tre_nod *) res->next)->rht = NULL;
            ((struct bee_tre_nod *) res->next)->lft = NULL;

            return res;
        }
    }
}

int len_avl(struct list_node *rtt) {
    struct list_node *lft = ((struct list_node *) ((struct bee_tre_nod *) rtt->next)->lft);
    int lft_len = 0;
    if (lft) lft_len = len_avl(lft);

    struct list_node *rht = ((struct list_node *) ((struct bee_tre_nod *) rtt->next)->rht);
    int rht_len = 0;
    if (rht) rht_len = len_avl(rht);

    return 1 + ((lft_len > rht_len) ? lft_len : rht_len);
}

int get_bal(struct list_node *rtt) {
    int len_lft = 0, len_rht = 0;
    if (((struct bee_tre_nod *) rtt->next)->rht)
        len_rht += len_avl((struct list_node *) ((struct bee_tre_nod *) rtt->next)->rht);
    if (((struct bee_tre_nod *) rtt->next)->lft)
        len_lft += len_avl((struct list_node *) ((struct bee_tre_nod *) rtt->next)->lft);

    return len_lft - len_rht;
}

//rotations
void rht_rht(struct list_node *rtt) {
    //salvam z
    struct bee_tre_nod *z = (struct bee_tre_nod *) rtt->next;
    //y se duce in locul lui z
    rtt->next = ((struct list_node *) ((struct bee_tre_nod *) rtt->next)->lft)->next;

    //chestii perliculoase
    ((struct list_node *) z->lft)->next = (struct list_node *) z;

    //salvam T3
    struct list_node *T3 = (struct list_node *) ((struct bee_tre_nod *) rtt->next)->rht;
    //adugam x la y
    ((struct bee_tre_nod *) rtt->next)->rht = z->lft;
    //aduagam T3 la z
    z->lft = (struct bee_tre_nod *) T3;
}

void lft_lft(struct list_node *rtt) {
    //salvam z
    struct bee_tre_nod *z = (struct bee_tre_nod *) rtt->next;
    //y se duce in locul lui z
    rtt->next = ((struct list_node *) ((struct bee_tre_nod *) rtt->next)->rht)->next;

    //chestii perliculoase
    ((struct list_node *) z->rht)->next = (struct list_node *) z;

    //salvam T2
    struct list_node *T2 = (struct list_node *) ((struct bee_tre_nod *) rtt->next)->lft;
    //adugam x la y
    ((struct bee_tre_nod *) rtt->next)->lft = z->rht;
    //aduagam T3 la z
    z->rht = (struct bee_tre_nod *) T2;
}

void lft_rht(struct list_node *rtt) {
    lft_lft((struct list_node *) ((struct bee_tre_nod *) rtt->next)->lft);
    rht_rht(rtt);
}

void rht_lft(struct list_node *rtt) {
    rht_rht((struct list_node *) ((struct bee_tre_nod *) rtt->next)->rht);
    lft_lft(rtt);
}

int blc_avl(struct list_node *rtt, struct list_node *nod) {
    int res = 0;
    if (rtt != nod) {
        if (((struct bee_tre_nod *) rtt->next)->rht)
            res += blc_avl((struct list_node *) ((struct bee_tre_nod *) rtt->next)->rht, nod);
        if (((struct bee_tre_nod *) rtt->next)->lft)
            res += blc_avl((struct list_node *) ((struct bee_tre_nod *) rtt->next)->lft, nod);
    } else
        return 1;

    if (res) {
        int bal = get_bal(rtt);
        struct team *cur = ((struct bee_tre_nod *) rtt->next)->val;
        fprintf(stderr, "cur -> %ld\n", cur);
        if (((struct bee_tre_nod *) rtt->next)->lft) {
            struct team *lft = ((struct bee_tre_nod *) ((struct list_node *) ((struct bee_tre_nod *) rtt->next)->lft)->next)->val;
            fprintf(stderr, "%s lft\n", lft->name);
            if (bal > 1 && tem_pts(cur) < tem_pts(lft)) {
                fprintf(stderr, "lr\n");
                lft_rht(rtt);
            } else if (bal > 1 && tem_pts(cur) >= tem_pts(lft)) {
                fprintf(stderr, "rr\n");
                rht_rht(rtt);
            }
        }
        if (((struct bee_tre_nod *) rtt->next)->rht) {
            struct team *rht = ((struct bee_tre_nod *) ((struct list_node *) ((struct bee_tre_nod *) rtt->next)->rht)->next)->val;
            fprintf(stderr, "%s rht\n", rht->name);
            if (bal < -1 && tem_pts(cur) >= tem_pts(rht)) {
                fprintf(stderr, "ll\n");
                lft_lft(rtt);
            } else if (bal < -1 && tem_pts(cur) < tem_pts(rht)) {
                fprintf(stderr, "rl\n");
                rht_lft(rtt);
            }

        }
    }

    return res;
}

void ins_val(struct list_node *rtt, struct team *add) {
    struct list_node *res = add_avl_nod(rtt, add);
    blc_avl(rtt, res);
}

void print2(struct list_node *hed, FILE *out) {
    if (((struct bee_tre_nod *) hed->next)->lft) {
        struct list_node *lft = (struct list_node *) ((struct bee_tre_nod *) hed->next)->lft;
        if (((struct bee_tre_nod *) lft->next)->lft) {
            struct bee_tre_nod *lft_lft = (struct bee_tre_nod *) ((struct list_node *) ((struct bee_tre_nod *) lft->next)->lft)->next;
            fprintf(out, "%s\n", ((struct team *) lft_lft->val)->name);
        }
        if (((struct bee_tre_nod *) lft->next)->rht) {
            struct bee_tre_nod *lft_rht = (struct bee_tre_nod *) ((struct list_node *) ((struct bee_tre_nod *) lft->next)->rht)->next;
            fprintf(out, "%s\n", ((struct team *) lft_rht->val)->name);
        }

    }
    if (((struct bee_tre_nod *) hed->next)->rht) {
        struct list_node *rht = (struct list_node *) ((struct bee_tre_nod *) hed->next)->rht;
        if (((struct bee_tre_nod *) rht->next)->lft) {
            struct bee_tre_nod *rht_lft = (struct bee_tre_nod *) ((struct list_node *) ((struct bee_tre_nod *) rht->next)->lft)->next;
            fprintf(out, "%s\n", ((struct team *) rht_lft->val)->name);
        }
        if (((struct bee_tre_nod *) rht->next)->rht) {
            struct bee_tre_nod *rht_rht = (struct bee_tre_nod *) ((struct list_node *) ((struct bee_tre_nod *) rht->next)->rht)->next;
            fprintf(out, "%s\n", ((struct team *) rht_rht->val)->name);
        }
    }
}

extern void task5(struct list_node *lst) {
    struct list_node *hed_lst_nod = malloc(sizeof(struct list_node));
    hed_lst_nod->value = NULL;
    hed_lst_nod->next = (struct list_node *) malloc(sizeof(struct bee_tre_nod));

    ((struct bee_tre_nod *) hed_lst_nod->next)->lft = NULL;
    ((struct bee_tre_nod *) hed_lst_nod->next)->rht = NULL;
    ((struct bee_tre_nod *) hed_lst_nod->next)->val = lst->next->value;

    for (struct list_node *i = lst->next->next; i; i = i->next) {
        ins_val(hed_lst_nod, i->value);
        fprintf(stderr, "=> %d\n", get_bal(hed_lst_nod));
    }

    print2(hed_lst_nod, stderr);
}
