typedef struct sequence *Sequence;

void build(void);
void length(Sequence);
void get_at(Sequence, int);
void set_at(Sequence, int);
void insert_at(Sequence, int);
void delete_at(Sequence, int);
void insert_first(Sequence);
void delete_first(Sequence);
void insert_last(Sequence);
void delete_last(Sequence);
