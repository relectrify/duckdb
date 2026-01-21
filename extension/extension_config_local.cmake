duckdb_extension_load(ducklake
    GIT_URL https://github.com/duckdb/ducklake
    GIT_TAG de813ff4d052bffe3e9e7ffcdc31d18ca38e5ecd
)
duckdb_extension_load(httpfs
    GIT_URL https://github.com/duckdb/duckdb-httpfs
    GIT_TAG 9c7d34977b10346d0b4cbbde5df807d1dab0b2bf
    INCLUDE_DIR src/include
)
duckdb_extension_load(mysql_scanner
    GIT_URL https://github.com/duckdb/duckdb-mysql
    GIT_TAG ecb76de715dfe0b5bba52f4fc8bde87186dd486f
)
duckdb_extension_load(postgres_scanner
    GIT_URL https://github.com/duckdb/duckdb-postgres
    GIT_TAG b63ef4b1eb007320840b6d1760f3c9b139bb3b49
)
