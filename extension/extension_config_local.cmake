duckdb_extension_load(ducklake
    GIT_URL https://github.com/duckdb/ducklake
    GIT_TAG d8a1881e22516ea3d186d73e83c65fe5bd1a1dc4
)
duckdb_extension_load(httpfs
    GIT_URL https://github.com/duckdb/duckdb-httpfs
    GIT_TAG 827222fb45a043a7a852d1f7aae46901492a3cda
)
duckdb_extension_load(mysql_scanner
    GIT_URL https://github.com/duckdb/duckdb-mysql
    GIT_TAG 7267164dab3409e943261aeee6ae32f1b00847a7
    SUBMODULES database-connector
    APPLY_PATCHES
)
duckdb_extension_load(postgres_scanner
    GIT_URL https://github.com/duckdb/duckdb-postgres
    GIT_TAG 41223e51559cd581f1c06e170b71c71df25bbaac
    SUBMODULES database-connector
    APPLY_PATCHES
)
duckdb_extension_load(aws
    GIT_URL https://github.com/duckdb/duckdb-aws
    GIT_TAG efa54a990e16c976576685dd4134d2478cf5a574
)
duckdb_extension_load(quack
    GIT_URL https://github.com/duckdb/duckdb-quack
    GIT_TAG c1548111c1bfd16207e22fd3cb7e4bde1335b9d0
)
