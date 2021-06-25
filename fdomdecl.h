//STRUCTURES

typedef struct listtype1{//A circular list of GENs, stores data, next, and previous terms
  GEN data; 
  struct listtype1 *next;
  struct listtype1 *prev;
}clist;

typedef struct listtype2{//A generic linked list of GENs, stores data and next term
  GEN data; 
  struct listtype2 *next;
}glist;

typedef struct listtype3{//A generic linked list of longs, stores data and next term
  long data; 
  struct listtype3 *next;
}llist;


//FDOM METHODS


//SECTION 1: BASE METHODS

//INFINITY 
GEN divoo(GEN a, GEN b);

//LISTS
void glist_free(glist *l);
GEN glist_pop(glist **head_ref);
void glist_putstart(glist **head_ref, GEN new_data);
GEN glist_togvec(glist *l, long length, int dir);
GEN glist_togvec_append(glist *l, GEN v, long length, int dir);
void llist_free(llist *l);
long llist_pop(llist **head_ref);
void llist_putstart(llist **head_ref, long new_data);
GEN llist_togvec(llist *l, long length, int dir);
GEN llist_tovecsmall(llist *l, long length, int dir);

//SHORT VECTORS IN LATTICES
GEN mat_nfcholesky(GEN nf, GEN A);

//SECTION 2: GEOMETRY METHODS

//BASIC LINE, CIRCLE, AND POINT OPERATIONS
GEN mat_eval(GEN M, GEN x);

//DISTANCES/AREAS
GEN hdiscarea(GEN R, long prec);
GEN hdiscradius(GEN area, long prec);
GEN hdist(GEN z1, GEN z2, long prec);
GEN hdist_ud(GEN z1, GEN z2, long prec);

//FUNDAMENTAL DOMAIN COMPUTATION
GEN isometriccircle_mats(GEN g, GEN mats, GEN *data, GEN (*gamtopsl)(GEN *, GEN, long), GEN tol, long prec);
GEN isometriccircle_psu(GEN g, GEN tol, long prec);
GEN normalizedbasis(GEN G, GEN U, GEN mats, GEN gamid, GEN *data, GEN (*gamtopsl)(GEN *, GEN, long), GEN (*eltmul)(GEN *, GEN, GEN), GEN (*eltinv)(GEN *, GEN), int (*istriv)(GEN *, GEN), GEN tol, long prec);
GEN normalizedboundary(GEN G, GEN mats, GEN id, GEN *data, GEN (*gamtopsl)(GEN *, GEN, long), GEN tol, long prec);
GEN psltopsu(GEN g, GEN p);
GEN psltopsu_mats(GEN g, GEN M);
GEN psltopsu_transmats(GEN p);
GEN randompoint_ud(GEN R, long prec);
GEN randompoint_udarc(GEN R, GEN ang1, GEN ang2, long prec);
GEN reduceelt_givennormbound(GEN U, GEN g, GEN z, GEN gamid, GEN *data, GEN (*gamtopsl)(GEN *, GEN, long), GEN (*eltmul)(GEN *, GEN, GEN), GEN tol, long prec);
GEN reduceelt_givenpsu(GEN G, GEN Gmats, GEN g, GEN gmat, GEN z, GEN gamid, GEN *data, GEN (*eltmul)(GEN *, GEN, GEN), GEN tol, long prec);
GEN reducepoint(GEN U, GEN z, GEN gamid, GEN *data, GEN (*eltmul)(GEN *, GEN, GEN), GEN tol, long prec);
GEN rootgeodesic_ud(GEN M, GEN mats, GEN tol, long prec);
GEN rootgeodesic_uhp(GEN M, GEN tol, long prec);

//FUNDAMENTAL DOMAIN OTHER COMPUTATIONS
GEN minimalcycles_bytype(GEN U, GEN gamid, GEN *data, GEN (*eltmul)(GEN *, GEN, GEN), GEN (*elttrace)(GEN *, GEN), int (*istriv)(GEN *, GEN));
GEN rootgeodesic_fd(GEN U, GEN g, GEN gamid, GEN *data, GEN (*gamtopsl)(GEN *, GEN, long), GEN (*eltmul)(GEN *, GEN, GEN), GEN (*eltinv)(GEN *, GEN), GEN tol, long prec);
GEN presentation(GEN U, GEN gamid, GEN *data, GEN (*eltmul)(GEN *, GEN, GEN), GEN (*elttrace)(GEN *, GEN), int (*istriv)(GEN *, GEN));
GEN signature(GEN U, GEN gamid, GEN *data, GEN (*eltmul)(GEN *, GEN, GEN), GEN (*elttrace)(GEN *, GEN), int (*istriv)(GEN *, GEN));

//HELPER METHODS
GEN deftol(long prec);


//SECTION 3: QUATERNIONIC METHODS


//QUATERNION METHODS
GEN algfdom(GEN A, GEN p, int dispprogress, int dumppartial, GEN partialset, GEN ANRdata, long prec);
GEN algfdomarea(GEN A, int lessprec, long prec);
GEN algfdomminimalcycles(GEN A, GEN U, long prec);
GEN algfdompresentation(GEN A, GEN U, long prec);
GEN algfdomreduce(GEN A, GEN U, GEN g, GEN z, long prec);
GEN algfdomrootgeodesic(GEN A, GEN U, GEN g, long prec);
GEN algfdomsignature(GEN A, GEN U, long prec);
GEN algnormalizedbasis(GEN A, GEN G, GEN p, long prec);
GEN algnormalizedboundary(GEN A, GEN G, GEN p, long prec);
GEN algnormdisc(GEN A);
GEN algramifiedplacesf(GEN A);
GEN algsmallnorm1elts(GEN A, GEN C, GEN p, GEN z1, GEN z2, long prec);

//HELPER METHODS
GEN algnorm_chol(GEN nf, GEN decomp, GEN x);
GEN qalg_absrednormqf(GEN Q, GEN mats, GEN z1, GEN z2, GEN normformpart, long prec);
GEN qalg_fdomarea(GEN Q, long computeprec, long prec);
GEN qalg_fdominitialize(GEN A, long prec);
GEN qalg_normform(GEN Q);

//3: SHALLOW RETRIEVAL METHODS
GEN qalg_get_alg(GEN Q);
GEN qalg_get_rams(GEN Q);
GEN qalg_get_varnos(GEN Q);
GEN qalg_get_roots(GEN Q);

//TEMPORARY
GEN bestAval(GEN Q, long prec);
GEN algnormform(GEN A, long prec);
GEN algabsrednorm(GEN A, GEN p, GEN z1, GEN z2, long prec);
GEN algfdom_test(GEN A, GEN p, int dispprogress, int dumppartial, GEN partialset, GEN ANRdata, long prec);
GEN balltester(GEN x, GEN y, GEN R, long prec);
GEN algfdom_test2(GEN A, GEN p, int dispprogress, int dumppartial, GEN partialset, GEN ANRdata, long prec);
GEN qalg_smallnorm1elts_condition2(GEN Q, GEN C, GEN p, GEN z1, GEN z2, long maxN, long maxelts, GEN normform, GEN normformpart, long prec);
GEN algsmallnorm1elts_condition2(GEN A, GEN C, GEN p, GEN z1, GEN z2, long triesperelt, long maxelts, long prec);

//TEMPORARILY NON-STATIC
GEN qalg_smallnorm1elts_qfminim(GEN Q, GEN C, GEN p, GEN z1, GEN z2, long maxret, GEN normdecomp, GEN normformpart, long prec);
GEN qalg_smallnorm1elts_condition(GEN Q, GEN C, GEN p, GEN z1, GEN z2, long maxN, long maxelts, GEN normform, GEN normformpart, long prec);



//FDOM_EXTRA METHODS


//SECTION 1: GEOMETRY METHODS
void python_printarcs(GEN arcs, char *filename, int view, char *extrainput, long prec);
void python_plotviewer(char *input);
void python_printfdom(GEN U, char *filename, long prec);

//SECTION 2: QUATERNIONIC METHODS
GEN algmulvec(GEN A, GEN G, GEN L);
GEN algshimura(GEN F, GEN D, long place, long maxcomptime, int allowswap);
GEN algshimura_ab(GEN F, GEN D, long place, long maxcomptime, int allowswap);
GEN algswapab(GEN A);
GEN smallalgebras(GEN F, long nwant, GEN Dmin, GEN Dmax, long maxcomptime, int allowswap);

//SECTION 3: PRODUCING DATA FOR MY PAPER

//3: REGRESSIONS
GEN OLS(GEN X, GEN y, int retrsqr);
GEN rsquared(GEN X, GEN y, GEN fit);