# Review of design DATA_STORE_AURORA_0007

**Overview:**

Data Store as designed in AURORA-Reference-Component-Set uses sporadic interfaces for
CRUD operations. Sporadic interfaces use non-race condition methods to avoid
consistency problems as per [1].

[1] https://taste.tuxfamily.org/wiki/index.php?title=TASTE_Semantics#Semantics
