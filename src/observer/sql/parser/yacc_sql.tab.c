/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.tab.h"
#include "sql/parser/lex.yy.h"
// #include "common/log/log.h" // 包含C++中的头文件

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ParserContext {
  Query * ssql;
  size_t select_length;
  size_t condition_length;
  size_t from_length;
  size_t value_length;
  size_t insert_num;
  size_t order_num;
  Value values[MAX_NUM];
  Condition conditions[MAX_NUM];
  OrderOp orderOps[MAX_NUM];
  OrderDirect orderDirect;
  CompOp comp;
	char id[MAX_NUM];
} ParserContext;

//获取子串
char *substr(const char *s,int n1,int n2)/*从s中提取下标为n1~n2的字符组成一个新字符串，然后返回这个新串的首地址*/
{
  char *sp = malloc(sizeof(char) * (n2 - n1 + 2));
  int i, j = 0;
  for (i = n1; i <= n2; i++) {
    sp[j++] = s[i];
  }
  sp[j] = 0;
  return sp;
}

void yyerror(yyscan_t scanner, const char *str)
{
  ParserContext *context = (ParserContext *)(yyget_extra(scanner));
  query_reset(context->ssql);
  context->ssql->flag = SCF_ERROR;
  context->condition_length = 0;
  context->from_length = 0;
  context->select_length = 0;
  context->value_length = 0;
  context->insert_num = 0;
  context->order_num = 0;
  context->ssql->sstr.insertion.value_num = 0;
  printf("parse sql failed. error=%s", str);
}

ParserContext *get_context(yyscan_t scanner)
{
  return (ParserContext *)yyget_extra(scanner);
}

#define CONTEXT get_context(scanner)


#line 134 "yacc_sql.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "yacc_sql.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_IS = 4,                         /* IS  */
  YYSYMBOL_ISNOT = 5,                      /* ISNOT  */
  YYSYMBOL_ANULL = 6,                      /* ANULL  */
  YYSYMBOL_NULLABLE = 7,                   /* NULLABLE  */
  YYSYMBOL_NOTNULL = 8,                    /* NOTNULL  */
  YYSYMBOL_CREATE = 9,                     /* CREATE  */
  YYSYMBOL_DROP = 10,                      /* DROP  */
  YYSYMBOL_TABLE = 11,                     /* TABLE  */
  YYSYMBOL_TABLES = 12,                    /* TABLES  */
  YYSYMBOL_INDEX = 13,                     /* INDEX  */
  YYSYMBOL_UNIQUE = 14,                    /* UNIQUE  */
  YYSYMBOL_SELECT = 15,                    /* SELECT  */
  YYSYMBOL_MAX = 16,                       /* MAX  */
  YYSYMBOL_MIN = 17,                       /* MIN  */
  YYSYMBOL_COUNT = 18,                     /* COUNT  */
  YYSYMBOL_AVG = 19,                       /* AVG  */
  YYSYMBOL_DESC = 20,                      /* DESC  */
  YYSYMBOL_ASC = 21,                       /* ASC  */
  YYSYMBOL_ORDERBY = 22,                   /* ORDERBY  */
  YYSYMBOL_GROUPBY = 23,                   /* GROUPBY  */
  YYSYMBOL_SHOW = 24,                      /* SHOW  */
  YYSYMBOL_SYNC = 25,                      /* SYNC  */
  YYSYMBOL_INSERT = 26,                    /* INSERT  */
  YYSYMBOL_DELETE = 27,                    /* DELETE  */
  YYSYMBOL_UPDATE = 28,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 29,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 30,                    /* RBRACE  */
  YYSYMBOL_COMMA = 31,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 32,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 33,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 34,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 35,                     /* INT_T  */
  YYSYMBOL_STRING_T = 36,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 37,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 38,                    /* DATE_T  */
  YYSYMBOL_HELP = 39,                      /* HELP  */
  YYSYMBOL_EXIT = 40,                      /* EXIT  */
  YYSYMBOL_DOT = 41,                       /* DOT  */
  YYSYMBOL_INTO = 42,                      /* INTO  */
  YYSYMBOL_VALUES = 43,                    /* VALUES  */
  YYSYMBOL_FROM = 44,                      /* FROM  */
  YYSYMBOL_WHERE = 45,                     /* WHERE  */
  YYSYMBOL_AND = 46,                       /* AND  */
  YYSYMBOL_SET = 47,                       /* SET  */
  YYSYMBOL_ON = 48,                        /* ON  */
  YYSYMBOL_IN = 49,                        /* IN  */
  YYSYMBOL_NOTIN = 50,                     /* NOTIN  */
  YYSYMBOL_LOAD = 51,                      /* LOAD  */
  YYSYMBOL_DATA = 52,                      /* DATA  */
  YYSYMBOL_INFILE = 53,                    /* INFILE  */
  YYSYMBOL_EQ = 54,                        /* EQ  */
  YYSYMBOL_LT = 55,                        /* LT  */
  YYSYMBOL_GT = 56,                        /* GT  */
  YYSYMBOL_LE = 57,                        /* LE  */
  YYSYMBOL_GE = 58,                        /* GE  */
  YYSYMBOL_NE = 59,                        /* NE  */
  YYSYMBOL_NUMBER = 60,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 61,                     /* FLOAT  */
  YYSYMBOL_DATE = 62,                      /* DATE  */
  YYSYMBOL_ID = 63,                        /* ID  */
  YYSYMBOL_PATH = 64,                      /* PATH  */
  YYSYMBOL_SSS = 65,                       /* SSS  */
  YYSYMBOL_STAR = 66,                      /* STAR  */
  YYSYMBOL_STRING_V = 67,                  /* STRING_V  */
  YYSYMBOL_AGGOP = 68,                     /* AGGOP  */
  YYSYMBOL_YYACCEPT = 69,                  /* $accept  */
  YYSYMBOL_commands = 70,                  /* commands  */
  YYSYMBOL_command = 71,                   /* command  */
  YYSYMBOL_exit = 72,                      /* exit  */
  YYSYMBOL_help = 73,                      /* help  */
  YYSYMBOL_sync = 74,                      /* sync  */
  YYSYMBOL_begin = 75,                     /* begin  */
  YYSYMBOL_commit = 76,                    /* commit  */
  YYSYMBOL_rollback = 77,                  /* rollback  */
  YYSYMBOL_drop_table = 78,                /* drop_table  */
  YYSYMBOL_show_tables = 79,               /* show_tables  */
  YYSYMBOL_desc_table = 80,                /* desc_table  */
  YYSYMBOL_create_index = 81,              /* create_index  */
  YYSYMBOL_index_list = 82,                /* index_list  */
  YYSYMBOL_drop_index = 83,                /* drop_index  */
  YYSYMBOL_create_table = 84,              /* create_table  */
  YYSYMBOL_attr_def_list = 85,             /* attr_def_list  */
  YYSYMBOL_attr_def = 86,                  /* attr_def  */
  YYSYMBOL_is_nullable = 87,               /* is_nullable  */
  YYSYMBOL_number = 88,                    /* number  */
  YYSYMBOL_type = 89,                      /* type  */
  YYSYMBOL_ID_get = 90,                    /* ID_get  */
  YYSYMBOL_insert = 91,                    /* insert  */
  YYSYMBOL_multi_values = 92,              /* multi_values  */
  YYSYMBOL_value_list = 93,                /* value_list  */
  YYSYMBOL_value = 94,                     /* value  */
  YYSYMBOL_delete = 95,                    /* delete  */
  YYSYMBOL_update = 96,                    /* update  */
  YYSYMBOL_select = 97,                    /* select  */
  YYSYMBOL_aggregate_attr = 98,            /* aggregate_attr  */
  YYSYMBOL_aggregate_list = 99,            /* aggregate_list  */
  YYSYMBOL_count_attr = 100,               /* count_attr  */
  YYSYMBOL_select_attr = 101,              /* select_attr  */
  YYSYMBOL_attr_list = 102,                /* attr_list  */
  YYSYMBOL_rel_list = 103,                 /* rel_list  */
  YYSYMBOL_order = 104,                    /* order  */
  YYSYMBOL_order_list = 105,               /* order_list  */
  YYSYMBOL_orderby = 106,                  /* orderby  */
  YYSYMBOL_direction = 107,                /* direction  */
  YYSYMBOL_group = 108,                    /* group  */
  YYSYMBOL_groupby = 109,                  /* groupby  */
  YYSYMBOL_group_list = 110,               /* group_list  */
  YYSYMBOL_where = 111,                    /* where  */
  YYSYMBOL_condition_list = 112,           /* condition_list  */
  YYSYMBOL_condition = 113,                /* condition  */
  YYSYMBOL_subselect = 114,                /* subselect  */
  YYSYMBOL_subselect_attr = 115,           /* subselect_attr  */
  YYSYMBOL_subaggregate_attr = 116,        /* subaggregate_attr  */
  YYSYMBOL_subaggregate_list = 117,        /* subaggregate_list  */
  YYSYMBOL_subcount_attr = 118,            /* subcount_attr  */
  YYSYMBOL_subattr_list = 119,             /* subattr_list  */
  YYSYMBOL_subrel_list = 120,              /* subrel_list  */
  YYSYMBOL_comOp = 121,                    /* comOp  */
  YYSYMBOL_load_data = 122                 /* load_data  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   345

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  351

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   323


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   157,   157,   159,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   183,   188,   193,   199,   205,   211,   217,   223,   229,
     236,   242,   250,   252,   258,   265,   274,   276,   280,   291,
     304,   305,   306,   309,   312,   313,   314,   315,   318,   327,
     344,   346,   352,   354,   359,   362,   365,   369,   373,   379,
     389,   399,   417,   423,   429,   435,   440,   442,   448,   454,
     460,   465,   470,   475,   482,   487,   492,   497,   502,   505,
     507,   514,   521,   530,   532,   536,   538,   542,   544,   548,
     550,   555,   563,   566,   569,   573,   575,   579,   581,   586,
     592,   594,   599,   605,   607,   611,   613,   618,   639,   659,
     679,   701,   722,   743,   762,   770,   778,   786,   794,   802,
     813,   826,   832,   838,   844,   850,   855,   862,   869,   876,
     882,   884,   890,   896,   902,   907,   912,   917,   922,   924,
     929,   934,   941,   943,   947,   948,   949,   950,   951,   952,
     953,   954,   958
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "IS",
  "ISNOT", "ANULL", "NULLABLE", "NOTNULL", "CREATE", "DROP", "TABLE",
  "TABLES", "INDEX", "UNIQUE", "SELECT", "MAX", "MIN", "COUNT", "AVG",
  "DESC", "ASC", "ORDERBY", "GROUPBY", "SHOW", "SYNC", "INSERT", "DELETE",
  "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN", "TRX_COMMIT",
  "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T", "HELP", "EXIT",
  "DOT", "INTO", "VALUES", "FROM", "WHERE", "AND", "SET", "ON", "IN",
  "NOTIN", "LOAD", "DATA", "INFILE", "EQ", "LT", "GT", "LE", "GE", "NE",
  "NUMBER", "FLOAT", "DATE", "ID", "PATH", "SSS", "STAR", "STRING_V",
  "AGGOP", "$accept", "commands", "command", "exit", "help", "sync",
  "begin", "commit", "rollback", "drop_table", "show_tables", "desc_table",
  "create_index", "index_list", "drop_index", "create_table",
  "attr_def_list", "attr_def", "is_nullable", "number", "type", "ID_get",
  "insert", "multi_values", "value_list", "value", "delete", "update",
  "select", "aggregate_attr", "aggregate_list", "count_attr",
  "select_attr", "attr_list", "rel_list", "order", "order_list", "orderby",
  "direction", "group", "groupby", "group_list", "where", "condition_list",
  "condition", "subselect", "subselect_attr", "subaggregate_attr",
  "subaggregate_list", "subcount_attr", "subattr_list", "subrel_list",
  "comOp", "load_data", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323
};
#endif

#define YYPACT_NINF (-272)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -272,   135,  -272,   181,    99,   121,   -46,    11,    29,     9,
      26,   -26,    53,    62,    73,    82,    96,    39,  -272,  -272,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,
    -272,  -272,  -272,  -272,  -272,  -272,    43,    48,    90,    56,
      64,   105,   107,   136,   137,   -16,  -272,  -272,   120,   169,
     174,  -272,   115,   126,   166,  -272,  -272,  -272,  -272,  -272,
     161,   187,   142,   154,   215,   216,   157,   158,   113,   159,
     160,   143,  -272,   162,  -272,  -272,   183,   179,   164,   163,
     167,   168,   184,  -272,  -272,   199,   203,  -272,  -272,  -272,
     204,   205,    -7,   206,   206,   207,   210,    27,   233,   188,
     198,  -272,   212,    88,   217,   178,   213,   213,   213,   213,
     144,  -272,  -272,  -272,   185,   179,    40,  -272,  -272,  -272,
    -272,     3,  -272,    74,   201,  -272,    40,   234,   167,   219,
    -272,  -272,  -272,  -272,    14,   189,   221,   182,  -272,  -272,
    -272,  -272,   206,   206,   207,   229,   222,  -272,  -272,   191,
     226,   226,  -272,  -272,  -272,  -272,  -272,  -272,    12,    33,
      27,  -272,   179,   193,   212,   254,  -272,  -272,   200,  -272,
     227,   196,   232,   235,   236,   237,  -272,  -272,  -272,   208,
     239,    40,   238,    59,   248,  -272,  -272,  -272,  -272,  -272,
     228,  -272,   201,   264,   267,  -272,  -272,  -272,   242,   211,
     243,   227,   214,   218,   113,   220,    -1,   244,   223,   273,
     222,   247,   226,   226,    21,   130,   224,  -272,  -272,  -272,
     150,  -272,   276,   250,   252,   255,   258,   259,  -272,  -272,
     230,  -272,   208,  -272,    -5,  -272,  -272,  -272,   261,   281,
    -272,  -272,   251,  -272,  -272,   262,   265,   266,   268,    -3,
    -272,   256,  -272,  -272,  -272,  -272,   293,   213,   213,   213,
     213,   -10,   244,   240,   241,  -272,    40,  -272,   245,   246,
     249,   125,   253,   257,   145,  -272,   260,  -272,  -272,  -272,
    -272,  -272,  -272,  -272,     4,   270,   222,  -272,   269,   272,
    -272,  -272,  -272,   275,   277,    66,   279,   279,   280,   263,
    -272,  -272,   283,   284,   284,   284,   284,   149,  -272,  -272,
    -272,   271,   179,   270,   247,   186,  -272,  -272,  -272,  -272,
     279,   279,   280,   239,  -272,  -272,   285,   288,   289,   290,
    -272,  -272,  -272,   291,   274,   278,   125,   282,  -272,   292,
     294,   295,   297,   284,   284,   284,   284,  -272,  -272,  -272,
    -272
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,    20,
      19,    14,    15,    16,    17,     9,    10,    11,    12,    13,
       8,     5,     7,     6,     4,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,    74,    78,     0,     0,
       0,    23,     0,     0,     0,    24,    25,    26,    22,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,     0,    29,    28,     0,   103,     0,     0,
       0,     0,     0,    27,    34,     0,     0,    73,    71,    72,
       0,     0,    79,    79,    79,    83,     0,     0,     0,     0,
       0,    48,    36,     0,     0,     0,    66,    66,    66,    66,
       0,    80,    77,    75,     0,   103,     0,    58,    54,    55,
      57,     0,    56,     0,   105,    59,     0,     0,     0,     0,
      44,    45,    46,    47,    40,     0,     0,     0,    62,    63,
      65,    64,    79,    79,    83,    85,    52,   150,   151,     0,
       0,     0,   144,   145,   146,   147,   148,   149,     0,     0,
       0,   104,   103,     0,    36,     0,    42,    41,     0,    39,
      32,     0,     0,     0,     0,     0,    81,    82,    84,    89,
      95,     0,     0,     0,     0,   116,   118,   109,   107,   114,
     110,   108,   105,     0,     0,    37,    35,    43,     0,     0,
       0,    32,     0,     0,     0,     0,    94,    87,    97,     0,
      52,    50,     0,     0,     0,     0,     0,   106,    60,   152,
      40,    33,     0,     0,     0,     0,     0,     0,    93,    92,
       0,    90,    89,    86,   100,    96,    61,    53,     0,     0,
     117,   119,     0,   111,   115,     0,     0,     0,     0,   138,
     121,     0,   125,   112,    38,    31,     0,    66,    66,    66,
      66,    94,    87,     0,     0,    98,     0,    49,     0,     0,
       0,     0,     0,     0,     0,   123,     0,    30,    67,    68,
      70,    69,    91,    88,   100,   100,    52,   113,     0,     0,
     137,   135,   136,     0,     0,   138,   138,   138,   142,     0,
     101,    99,     0,   130,   130,   130,   130,     0,   139,   124,
     122,     0,   103,   100,    50,     0,   126,   127,   129,   128,
     138,   138,   142,    95,   102,    51,     0,     0,     0,     0,
     140,   141,   143,     0,     0,     0,     0,     0,   120,     0,
       0,     0,     0,   130,   130,   130,   130,   131,   132,   134,
     133
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,
    -272,  -272,  -272,    97,  -272,  -272,   165,   202,    86,  -272,
    -272,  -272,  -272,    17,  -206,  -110,  -272,  -272,  -272,  -272,
    -106,   124,  -272,    28,   192,  -272,    70,   101,    77,    16,
    -272,  -271,  -115,   148,   175,  -146,  -272,  -272,  -163,     6,
    -266,    22,  -114,  -272
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   200,    29,    30,   129,   102,   169,   198,
     134,   103,    31,   239,   182,   123,    32,    33,    34,    47,
     138,    90,    48,    72,   115,   180,   233,   207,   231,   209,
     235,   265,    98,   161,   124,   185,   251,   252,   316,   293,
     275,   312,   158,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     145,   139,   140,   141,   237,   186,   146,   147,   148,   159,
     228,   229,   189,   300,   301,    70,   162,    49,   117,   228,
     229,   166,   167,    50,    70,    71,   263,   117,   273,   308,
     309,   310,    51,   117,   110,   263,   264,    54,   274,   117,
     230,   184,   324,   168,   149,   299,   117,   193,   188,   191,
     184,    52,   150,   151,   330,   331,    55,   152,   153,   154,
     155,   156,   157,   147,   148,    56,   240,   241,   244,   214,
      53,   210,   118,   119,   120,   187,    57,   122,   147,   148,
     302,   118,   119,   120,   242,    58,   122,   118,   119,   120,
     121,    60,   122,   118,   119,   120,   190,   273,   122,    59,
     118,   119,   120,    63,   243,   122,    61,   307,   212,   213,
      39,    62,    40,   152,   153,   154,   155,   156,   157,    64,
     111,   112,   113,   130,   131,   132,   133,    65,   152,   153,
     154,   155,   156,   157,    66,     2,    67,    41,    42,    43,
      44,   317,   318,   319,     3,     4,   245,   246,   247,   248,
       5,   278,   279,   280,   281,     6,   286,   166,   167,     7,
       8,     9,    10,    11,    73,    68,    69,    12,    13,    14,
     176,   177,    74,    87,    15,    16,    88,    75,    76,    89,
     347,   348,   349,   350,    45,   290,    17,    46,   291,    77,
      81,   292,    36,   249,    37,    38,   250,   323,   172,   173,
     174,   175,   326,   327,   328,   329,    93,   142,   296,    94,
     143,   297,   320,    78,    79,   321,    80,    82,    83,    84,
      85,    86,    91,    92,    97,    95,    96,    99,   100,   106,
     101,   104,   105,   107,   108,   109,   125,    70,   114,   116,
     127,   136,   126,   128,   137,   163,   135,   160,   144,   165,
     171,   179,   170,   181,   183,   184,   194,   196,   199,   201,
     197,   202,   208,   215,   203,   204,   205,   218,   211,   216,
     219,   206,   220,   222,   221,   232,   236,   224,   238,   255,
     256,   225,   257,   227,   267,   258,   234,   253,   259,   260,
     266,   269,   268,   261,   270,   271,   277,   272,   223,   303,
     276,   263,   304,   284,   285,   305,   254,   306,   287,   288,
     273,   311,   289,   314,   334,   315,   294,   335,   336,   337,
     295,   338,   343,   298,   344,   345,   313,   346,   226,   195,
     164,   325,   283,   262,   322,   192,   178,   339,   282,   333,
     217,   340,   341,     0,   332,   342
};

static const yytype_int16 yycheck[] =
{
     115,   107,   108,   109,   210,   151,   116,     4,     5,   123,
      20,    21,   158,   284,   285,    31,   126,    63,     6,    20,
      21,     7,     8,    12,    31,    41,    31,     6,    31,   295,
     296,   297,     3,     6,    41,    31,    41,    63,    41,     6,
      41,    29,   313,    29,    41,    41,     6,   162,   158,   159,
      29,    42,    49,    50,   320,   321,     3,    54,    55,    56,
      57,    58,    59,     4,     5,     3,   212,   213,   214,   183,
      44,   181,    60,    61,    62,    63,     3,    65,     4,     5,
     286,    60,    61,    62,    63,     3,    65,    60,    61,    62,
      63,    52,    65,    60,    61,    62,    63,    31,    65,     3,
      60,    61,    62,    13,   214,    65,    63,    41,    49,    50,
      11,    63,    13,    54,    55,    56,    57,    58,    59,    63,
      92,    93,    94,    35,    36,    37,    38,    63,    54,    55,
      56,    57,    58,    59,    29,     0,    29,    16,    17,    18,
      19,   304,   305,   306,     9,    10,    16,    17,    18,    19,
      15,   257,   258,   259,   260,    20,   266,     7,     8,    24,
      25,    26,    27,    28,    44,    29,    29,    32,    33,    34,
     142,   143,     3,    60,    39,    40,    63,     3,    63,    66,
     343,   344,   345,   346,    63,    60,    51,    66,    63,    63,
      48,    66,    11,    63,    13,    14,    66,   312,    16,    17,
      18,    19,    16,    17,    18,    19,    63,    63,    63,    66,
      66,    66,    63,    47,    53,    66,    29,    63,     3,     3,
      63,    63,    63,    63,    45,    63,    43,    63,    65,    30,
      63,    63,    48,    30,    30,    30,     3,    31,    31,    29,
      42,    63,    54,    31,    31,    11,    29,    46,    63,    30,
      29,    22,    63,    31,    63,    29,    63,     3,    31,    63,
      60,    29,    23,    15,    29,    29,    29,     3,    30,    41,
       3,    63,    30,    30,    63,    31,     3,    63,    31,     3,
      30,    63,    30,    63,     3,    30,    63,    63,    30,    30,
      29,    29,    41,    63,    29,    29,     3,    29,   201,    30,
      44,    31,    30,    63,    63,    30,   220,    30,    63,    63,
      31,    31,    63,    30,    29,    31,    63,    29,    29,    29,
      63,    30,    30,    63,    30,    30,    63,    30,   204,   164,
     128,   314,   262,   232,    63,   160,   144,    63,   261,   323,
     192,    63,   336,    -1,   322,    63
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    70,     0,     9,    10,    15,    20,    24,    25,    26,
      27,    28,    32,    33,    34,    39,    40,    51,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    83,
      84,    91,    95,    96,    97,   122,    11,    13,    14,    11,
      13,    16,    17,    18,    19,    63,    66,    98,   101,    63,
      12,     3,    42,    44,    63,     3,     3,     3,     3,     3,
      52,    63,    63,    13,    63,    63,    29,    29,    29,    29,
      31,    41,   102,    44,     3,     3,    63,    63,    47,    53,
      29,    48,    63,     3,     3,    63,    63,    60,    63,    66,
     100,    63,    63,    63,    66,    63,    43,    45,   111,    63,
      65,    63,    86,    90,    63,    48,    30,    30,    30,    30,
      41,   102,   102,   102,    31,   103,    29,     6,    60,    61,
      62,    63,    65,    94,   113,     3,    54,    42,    31,    85,
      35,    36,    37,    38,    89,    29,    63,    31,    99,    99,
      99,    99,    63,    66,    63,   111,    94,     4,     5,    41,
      49,    50,    54,    55,    56,    57,    58,    59,   121,   121,
      46,   112,    94,    11,    86,    30,     7,     8,    29,    87,
      63,    29,    16,    17,    18,    19,   102,   102,   103,    22,
     104,    31,    93,    63,    29,   114,   114,    63,    94,   114,
      63,    94,   113,   111,    63,    85,     3,    60,    88,    31,
      82,    63,    29,    29,    29,    29,    63,   106,    23,   108,
      94,    30,    49,    50,   121,    15,    41,   112,     3,     3,
      30,    63,    30,    82,    63,    63,   100,    63,    20,    21,
      41,   107,    31,   105,    63,   109,     3,    93,    31,    92,
     114,   114,    63,    94,   114,    16,    17,    18,    19,    63,
      66,   115,   116,    63,    87,     3,    30,    30,    30,    30,
      30,    63,   106,    31,    41,   110,    29,     3,    41,    29,
      29,    29,    29,    31,    41,   119,    44,     3,    99,    99,
      99,    99,   107,   105,    63,    63,    94,    63,    63,    63,
      60,    63,    66,   118,    63,    63,    63,    66,    63,    41,
     110,   110,    93,    30,    30,    30,    30,    41,   119,   119,
     119,    31,   120,    63,    30,    31,   117,   117,   117,   117,
      63,    66,    63,   111,   110,    92,    16,    17,    18,    19,
     119,   119,   120,   108,    29,    29,    29,    29,    30,    63,
      63,   118,    63,    30,    30,    30,    30,   117,   117,   117,
     117
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    69,    70,    70,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    81,    82,    82,    83,    84,    85,    85,    86,    86,
      87,    87,    87,    88,    89,    89,    89,    89,    90,    91,
      92,    92,    93,    93,    94,    94,    94,    94,    94,    95,
      96,    97,    98,    98,    98,    98,    99,    99,    99,    99,
      99,   100,   100,   100,   101,   101,   101,   101,   101,   102,
     102,   102,   102,   103,   103,   104,   104,   105,   105,   106,
     106,   106,   107,   107,   107,   108,   108,   109,   109,   109,
     110,   110,   110,   111,   111,   112,   112,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     114,   115,   115,   115,   115,   115,   116,   116,   116,   116,
     117,   117,   117,   117,   117,   118,   118,   118,   119,   119,
     119,   119,   120,   120,   121,   121,   121,   121,   121,   121,
     121,   121,   122
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     4,     3,     3,
      11,    10,     0,     2,     4,     8,     0,     3,     6,     3,
       0,     1,     1,     1,     1,     1,     1,     1,     1,    10,
       0,     6,     0,     3,     1,     1,     1,     1,     1,     5,
       8,     9,     5,     5,     5,     5,     0,     6,     6,     6,
       6,     1,     1,     1,     1,     4,     2,     4,     1,     0,
       3,     5,     5,     0,     3,     0,     3,     0,     3,     0,
       2,     4,     1,     1,     0,     0,     2,     0,     2,     4,
       0,     3,     5,     0,     3,     0,     3,     3,     3,     3,
       3,     5,     5,     7,     3,     5,     3,     5,     3,     5,
       9,     1,     4,     2,     4,     1,     5,     5,     5,     5,
       0,     6,     6,     6,     6,     1,     1,     1,     0,     3,
       5,     5,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     8
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, void *scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void *scanner)
{
  YY_USE (yyvaluep);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 21: /* exit: EXIT SEMICOLON  */
#line 183 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1505 "yacc_sql.tab.c"
    break;

  case 22: /* help: HELP SEMICOLON  */
#line 188 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1513 "yacc_sql.tab.c"
    break;

  case 23: /* sync: SYNC SEMICOLON  */
#line 193 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1521 "yacc_sql.tab.c"
    break;

  case 24: /* begin: TRX_BEGIN SEMICOLON  */
#line 199 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1529 "yacc_sql.tab.c"
    break;

  case 25: /* commit: TRX_COMMIT SEMICOLON  */
#line 205 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1537 "yacc_sql.tab.c"
    break;

  case 26: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 211 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1545 "yacc_sql.tab.c"
    break;

  case 27: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 217 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1554 "yacc_sql.tab.c"
    break;

  case 28: /* show_tables: SHOW TABLES SEMICOLON  */
#line 223 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1562 "yacc_sql.tab.c"
    break;

  case 29: /* desc_table: DESC ID SEMICOLON  */
#line 229 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1571 "yacc_sql.tab.c"
    break;

  case 30: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE ID index_list RBRACE SEMICOLON  */
#line 237 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 1);
			add_index_attr(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
		}
#line 1581 "yacc_sql.tab.c"
    break;

  case 31: /* create_index: CREATE INDEX ID ON ID LBRACE ID index_list RBRACE SEMICOLON  */
#line 243 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 0);
			add_index_attr(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
		}
#line 1591 "yacc_sql.tab.c"
    break;

  case 33: /* index_list: COMMA ID  */
#line 252 "yacc_sql.y"
                {
  		add_index_attr(&CONTEXT->ssql->sstr.create_index, (yyvsp[0].string));
	}
#line 1599 "yacc_sql.tab.c"
    break;

  case 34: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 259 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1608 "yacc_sql.tab.c"
    break;

  case 35: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 266 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1620 "yacc_sql.tab.c"
    break;

  case 37: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 276 "yacc_sql.y"
                                  {    }
#line 1626 "yacc_sql.tab.c"
    break;

  case 38: /* attr_def: ID_get type LBRACE number RBRACE is_nullable  */
#line 281 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-4].number), (yyvsp[-2].number),(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_length++;
		}
#line 1641 "yacc_sql.tab.c"
    break;

  case 39: /* attr_def: ID_get type is_nullable  */
#line 292 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-1].number), 4,(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
#line 1656 "yacc_sql.tab.c"
    break;

  case 40: /* is_nullable: %empty  */
#line 304 "yacc_sql.y"
        {(yyval.number) = 0;}
#line 1662 "yacc_sql.tab.c"
    break;

  case 41: /* is_nullable: NOTNULL  */
#line 305 "yacc_sql.y"
                  {(yyval.number) = 0;}
#line 1668 "yacc_sql.tab.c"
    break;

  case 42: /* is_nullable: NULLABLE  */
#line 306 "yacc_sql.y"
                   {(yyval.number) = 1;}
#line 1674 "yacc_sql.tab.c"
    break;

  case 43: /* number: NUMBER  */
#line 309 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1680 "yacc_sql.tab.c"
    break;

  case 44: /* type: INT_T  */
#line 312 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1686 "yacc_sql.tab.c"
    break;

  case 45: /* type: STRING_T  */
#line 313 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1692 "yacc_sql.tab.c"
    break;

  case 46: /* type: FLOAT_T  */
#line 314 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1698 "yacc_sql.tab.c"
    break;

  case 47: /* type: DATE_T  */
#line 315 "yacc_sql.y"
                {(yyval.number)=DATES; }
#line 1704 "yacc_sql.tab.c"
    break;

  case 48: /* ID_get: ID  */
#line 319 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1713 "yacc_sql.tab.c"
    break;

  case 49: /* insert: INSERT INTO ID VALUES LBRACE value value_list RBRACE multi_values SEMICOLON  */
#line 328 "yacc_sql.y"
                {
			// CONTEXT->values[CONTEXT->value_length++] = *$6;

			CONTEXT->ssql->flag=SCF_INSERT;//"insert";
			// CONTEXT->ssql->sstr.insertion.relation_name = $3;
			// CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
			// for(i = 0; i < CONTEXT->value_length; i++){
			// 	CONTEXT->ssql->sstr.insertion.values[i] = CONTEXT->values[i];
      // }
			inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-7].string), CONTEXT->values, CONTEXT->value_length, CONTEXT->insert_num);

      //临时变量清零
      CONTEXT->value_length=0;
      CONTEXT->insert_num=0;
    }
#line 1733 "yacc_sql.tab.c"
    break;

  case 51: /* multi_values: COMMA LBRACE value value_list RBRACE multi_values  */
#line 346 "yacc_sql.y"
                                                       {
  		// CONTEXT->values[CONTEXT->value_length++] = *$3;
  		CONTEXT->insert_num++;
	  }
#line 1742 "yacc_sql.tab.c"
    break;

  case 53: /* value_list: COMMA value value_list  */
#line 354 "yacc_sql.y"
                              { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1750 "yacc_sql.tab.c"
    break;

  case 54: /* value: NUMBER  */
#line 359 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1758 "yacc_sql.tab.c"
    break;

  case 55: /* value: FLOAT  */
#line 362 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1766 "yacc_sql.tab.c"
    break;

  case 56: /* value: SSS  */
#line 365 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1775 "yacc_sql.tab.c"
    break;

  case 57: /* value: DATE  */
#line 369 "yacc_sql.y"
          {
    			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
		value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
    }
#line 1784 "yacc_sql.tab.c"
    break;

  case 58: /* value: ANULL  */
#line 373 "yacc_sql.y"
          {
    		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
    }
#line 1792 "yacc_sql.tab.c"
    break;

  case 59: /* delete: DELETE FROM ID where SEMICOLON  */
#line 380 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1804 "yacc_sql.tab.c"
    break;

  case 60: /* update: UPDATE ID SET ID EQ value where SEMICOLON  */
#line 390 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			Value *value = &CONTEXT->values[0];
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-6].string), (yyvsp[-4].string), value, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1816 "yacc_sql.tab.c"
    break;

  case 61: /* select: SELECT select_attr FROM ID rel_list where order group SEMICOLON  */
#line 400 "yacc_sql.y"
                {
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string));
			// selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 0);
			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
			selects_append_orderOps(&CONTEXT->ssql->sstr.selection,CONTEXT->orderOps,CONTEXT->order_num);
			CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
			// sub_selects_init(&CONTEXT->ssql->sstr.selection);
			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 1836 "yacc_sql.tab.c"
    break;

  case 62: /* aggregate_attr: MAX LBRACE ID RBRACE aggregate_list  */
#line 417 "yacc_sql.y"
                                        {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 1);
    }
#line 1847 "yacc_sql.tab.c"
    break;

  case 63: /* aggregate_attr: MIN LBRACE ID RBRACE aggregate_list  */
#line 423 "yacc_sql.y"
                                          {
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
    			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 2);
    }
#line 1858 "yacc_sql.tab.c"
    break;

  case 64: /* aggregate_attr: AVG LBRACE ID RBRACE aggregate_list  */
#line 429 "yacc_sql.y"
                                          {
        		RelAttr attr;
        		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
        		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 3);
    }
#line 1869 "yacc_sql.tab.c"
    break;

  case 65: /* aggregate_attr: COUNT LBRACE count_attr RBRACE aggregate_list  */
#line 435 "yacc_sql.y"
                                                    {
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 4);
    }
#line 1877 "yacc_sql.tab.c"
    break;

  case 67: /* aggregate_list: COMMA MAX LBRACE ID RBRACE aggregate_list  */
#line 442 "yacc_sql.y"
                                                {
            		RelAttr attr;
            		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
            		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 1);
    }
#line 1888 "yacc_sql.tab.c"
    break;

  case 68: /* aggregate_list: COMMA MIN LBRACE ID RBRACE aggregate_list  */
#line 448 "yacc_sql.y"
                                                {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 2);
    }
#line 1899 "yacc_sql.tab.c"
    break;

  case 69: /* aggregate_list: COMMA AVG LBRACE ID RBRACE aggregate_list  */
#line 454 "yacc_sql.y"
                                                {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 3);
    }
#line 1910 "yacc_sql.tab.c"
    break;

  case 70: /* aggregate_list: COMMA COUNT LBRACE count_attr RBRACE aggregate_list  */
#line 460 "yacc_sql.y"
                                                          {
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 4);
    }
#line 1918 "yacc_sql.tab.c"
    break;

  case 71: /* count_attr: ID  */
#line 465 "yacc_sql.y"
       {
    	            	RelAttr attr;
                        relation_attr_init(&attr, NULL, (yyvsp[0].string));
                        selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    }
#line 1928 "yacc_sql.tab.c"
    break;

  case 72: /* count_attr: STAR  */
#line 470 "yacc_sql.y"
           {
        	        RelAttr attr;
                        relation_attr_init(&attr, NULL, "*");
                        selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 1938 "yacc_sql.tab.c"
    break;

  case 73: /* count_attr: NUMBER  */
#line 475 "yacc_sql.y"
             {
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, "*");
    			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    }
#line 1948 "yacc_sql.tab.c"
    break;

  case 74: /* select_attr: STAR  */
#line 482 "yacc_sql.y"
         {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1958 "yacc_sql.tab.c"
    break;

  case 75: /* select_attr: ID DOT STAR attr_list  */
#line 487 "yacc_sql.y"
                            {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    }
#line 1968 "yacc_sql.tab.c"
    break;

  case 76: /* select_attr: ID attr_list  */
#line 492 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1978 "yacc_sql.tab.c"
    break;

  case 77: /* select_attr: ID DOT ID attr_list  */
#line 497 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1988 "yacc_sql.tab.c"
    break;

  case 78: /* select_attr: aggregate_attr  */
#line 502 "yacc_sql.y"
                     {
    }
#line 1995 "yacc_sql.tab.c"
    break;

  case 80: /* attr_list: COMMA ID attr_list  */
#line 507 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 2007 "yacc_sql.tab.c"
    break;

  case 81: /* attr_list: COMMA ID DOT ID attr_list  */
#line 514 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2019 "yacc_sql.tab.c"
    break;

  case 82: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 521 "yacc_sql.y"
                                  {
      			RelAttr attr;
      			relation_attr_init(&attr, (yyvsp[-3].string), "*");
      			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
              // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
              // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
    }
#line 2031 "yacc_sql.tab.c"
    break;

  case 84: /* rel_list: COMMA ID rel_list  */
#line 532 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2039 "yacc_sql.tab.c"
    break;

  case 86: /* order: ORDERBY orderby order_list  */
#line 538 "yacc_sql.y"
                                 {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2047 "yacc_sql.tab.c"
    break;

  case 88: /* order_list: COMMA orderby order_list  */
#line 544 "yacc_sql.y"
                              {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2055 "yacc_sql.tab.c"
    break;

  case 90: /* orderby: ID direction  */
#line 550 "yacc_sql.y"
              {
			OrderOp orderOp;
			order_init(&orderOp,CONTEXT->orderDirect,NULL,(yyvsp[-1].string));
			CONTEXT->orderOps[CONTEXT->order_num++]=orderOp;
		}
#line 2065 "yacc_sql.tab.c"
    break;

  case 91: /* orderby: ID DOT ID direction  */
#line 555 "yacc_sql.y"
                                     {
			OrderOp orderOp;
			order_init(&orderOp,CONTEXT->orderDirect,(yyvsp[-3].string),(yyvsp[-1].string));
			CONTEXT->orderOps[CONTEXT->order_num++]=orderOp;
		}
#line 2075 "yacc_sql.tab.c"
    break;

  case 92: /* direction: ASC  */
#line 563 "yacc_sql.y"
        {
    		CONTEXT->orderDirect = ORASC;
    			}
#line 2083 "yacc_sql.tab.c"
    break;

  case 93: /* direction: DESC  */
#line 566 "yacc_sql.y"
           {
		CONTEXT->orderDirect = ORDESC;
			}
#line 2091 "yacc_sql.tab.c"
    break;

  case 94: /* direction: %empty  */
#line 569 "yacc_sql.y"
      {
    		CONTEXT->orderDirect = ORASC;
    }
#line 2099 "yacc_sql.tab.c"
    break;

  case 96: /* group: GROUPBY groupby  */
#line 575 "yacc_sql.y"
                      {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
}
#line 2107 "yacc_sql.tab.c"
    break;

  case 98: /* groupby: ID group_list  */
#line 581 "yacc_sql.y"
               {
	RelAttr attr;
	relation_attr_init(&attr, NULL, (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2117 "yacc_sql.tab.c"
    break;

  case 99: /* groupby: ID DOT ID group_list  */
#line 586 "yacc_sql.y"
                      {
	RelAttr attr;
	relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2127 "yacc_sql.tab.c"
    break;

  case 101: /* group_list: COMMA ID group_list  */
#line 594 "yacc_sql.y"
                     {
	RelAttr attr;
	relation_attr_init(&attr, NULL, (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2137 "yacc_sql.tab.c"
    break;

  case 102: /* group_list: COMMA ID DOT ID group_list  */
#line 599 "yacc_sql.y"
                            {
	RelAttr attr;
	relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2147 "yacc_sql.tab.c"
    break;

  case 104: /* where: WHERE condition condition_list  */
#line 607 "yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2155 "yacc_sql.tab.c"
    break;

  case 106: /* condition_list: AND condition condition_list  */
#line 613 "yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2163 "yacc_sql.tab.c"
    break;

  case 107: /* condition: ID comOp value  */
#line 619 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$ = ( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name = NULL;
			// $$->left_attr.attribute_name= $1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 0;
			// $$->right_attr.relation_name = NULL;
			// $$->right_attr.attribute_name = NULL;
			// $$->right_value = *$3;

		}
#line 2188 "yacc_sql.tab.c"
    break;

  case 108: /* condition: value comOp value  */
#line 640 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$ = ( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 0;
			// $$->right_attr.relation_name = NULL;
			// $$->right_attr.attribute_name = NULL;
			// $$->right_value = *$3;

		}
#line 2212 "yacc_sql.tab.c"
    break;

  case 109: /* condition: ID comOp ID  */
#line 660 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;

		}
#line 2236 "yacc_sql.tab.c"
    break;

  case 110: /* condition: value comOp ID  */
#line 680 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp=CONTEXT->comp;
			
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;
		
		}
#line 2262 "yacc_sql.tab.c"
    break;

  case 111: /* condition: ID DOT ID comOp value  */
#line 702 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=$1;
			// $$->left_attr.attribute_name=$3;
			// $$->comp=CONTEXT->comp;
			// $$->right_is_attr = 0;   //属性值
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=NULL;
			// $$->right_value =*$5;			
							
    }
#line 2287 "yacc_sql.tab.c"
    break;

  case 112: /* condition: value comOp ID DOT ID  */
#line 723 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;//属性值
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp =CONTEXT->comp;
			// $$->right_is_attr = 1;//属性
			// $$->right_attr.relation_name = $3;
			// $$->right_attr.attribute_name = $5;
									
    }
#line 2312 "yacc_sql.tab.c"
    break;

  case 113: /* condition: ID DOT ID comOp ID DOT ID  */
#line 744 "yacc_sql.y"
        {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;		//属性
			// $$->left_attr.relation_name=$1;
			// $$->left_attr.attribute_name=$3;
			// $$->comp =CONTEXT->comp;
			// $$->right_is_attr = 1;		//属性
			// $$->right_attr.relation_name=$5;
			// $$->right_attr.attribute_name=$7;
    }
#line 2335 "yacc_sql.tab.c"
    break;

  case 114: /* condition: ID comOp subselect  */
#line 762 "yacc_sql.y"
                         {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2348 "yacc_sql.tab.c"
    break;

  case 115: /* condition: ID DOT ID comOp subselect  */
#line 770 "yacc_sql.y"
                                {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2361 "yacc_sql.tab.c"
    break;

  case 116: /* condition: ID IN subselect  */
#line 778 "yacc_sql.y"
                      {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, EQUAL_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2374 "yacc_sql.tab.c"
    break;

  case 117: /* condition: ID DOT ID IN subselect  */
#line 786 "yacc_sql.y"
                             {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, EQUAL_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2387 "yacc_sql.tab.c"
    break;

  case 118: /* condition: ID NOTIN subselect  */
#line 794 "yacc_sql.y"
                         {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, NOT_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2400 "yacc_sql.tab.c"
    break;

  case 119: /* condition: ID DOT ID NOTIN subselect  */
#line 802 "yacc_sql.y"
                                {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, NOT_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2413 "yacc_sql.tab.c"
    break;

  case 120: /* subselect: LBRACE SELECT subselect_attr FROM ID subrel_list where group RBRACE  */
#line 814 "yacc_sql.y"
                {

			selects_append_relation(CONTEXT->ssql->sstr.selection.subSelect, (yyvsp[-4].string));
			selects_append_conditions(CONTEXT->ssql->sstr.selection.subSelect, CONTEXT->conditions, CONTEXT->condition_length);
			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 2428 "yacc_sql.tab.c"
    break;

  case 121: /* subselect_attr: STAR  */
#line 826 "yacc_sql.y"
         {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
		}
#line 2439 "yacc_sql.tab.c"
    break;

  case 122: /* subselect_attr: ID DOT STAR subattr_list  */
#line 832 "yacc_sql.y"
                               {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2450 "yacc_sql.tab.c"
    break;

  case 123: /* subselect_attr: ID subattr_list  */
#line 838 "yacc_sql.y"
                      {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
		}
#line 2461 "yacc_sql.tab.c"
    break;

  case 124: /* subselect_attr: ID DOT ID subattr_list  */
#line 844 "yacc_sql.y"
                                 {
	sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
	}
#line 2472 "yacc_sql.tab.c"
    break;

  case 125: /* subselect_attr: subaggregate_attr  */
#line 850 "yacc_sql.y"
                        {
    }
#line 2479 "yacc_sql.tab.c"
    break;

  case 126: /* subaggregate_attr: MAX LBRACE ID RBRACE subaggregate_list  */
#line 855 "yacc_sql.y"
                                           {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 1);
    }
#line 2491 "yacc_sql.tab.c"
    break;

  case 127: /* subaggregate_attr: MIN LBRACE ID RBRACE subaggregate_list  */
#line 862 "yacc_sql.y"
                                             {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
    			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 2);
    }
#line 2503 "yacc_sql.tab.c"
    break;

  case 128: /* subaggregate_attr: AVG LBRACE ID RBRACE subaggregate_list  */
#line 869 "yacc_sql.y"
                                             {
	sub_selects_init(&CONTEXT->ssql->sstr.selection);
        		RelAttr attr;
        		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
        		selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 3);
    }
#line 2515 "yacc_sql.tab.c"
    break;

  case 129: /* subaggregate_attr: COUNT LBRACE subcount_attr RBRACE subaggregate_list  */
#line 876 "yacc_sql.y"
                                                          {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 4);
    }
#line 2524 "yacc_sql.tab.c"
    break;

  case 131: /* subaggregate_list: COMMA MAX LBRACE ID RBRACE subaggregate_list  */
#line 884 "yacc_sql.y"
                                                   {
            		RelAttr attr;
            		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
            		selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 1);
    }
#line 2535 "yacc_sql.tab.c"
    break;

  case 132: /* subaggregate_list: COMMA MIN LBRACE ID RBRACE subaggregate_list  */
#line 890 "yacc_sql.y"
                                                   {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 2);
    }
#line 2546 "yacc_sql.tab.c"
    break;

  case 133: /* subaggregate_list: COMMA AVG LBRACE ID RBRACE subaggregate_list  */
#line 896 "yacc_sql.y"
                                                   {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 3);
    }
#line 2557 "yacc_sql.tab.c"
    break;

  case 134: /* subaggregate_list: COMMA COUNT LBRACE subcount_attr RBRACE subaggregate_list  */
#line 902 "yacc_sql.y"
                                                                {
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 4);
    }
#line 2565 "yacc_sql.tab.c"
    break;

  case 135: /* subcount_attr: ID  */
#line 907 "yacc_sql.y"
       {
    	            	RelAttr attr;
                        relation_attr_init(&attr, NULL, (yyvsp[0].string));
                        selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2575 "yacc_sql.tab.c"
    break;

  case 136: /* subcount_attr: STAR  */
#line 912 "yacc_sql.y"
           {
        	        RelAttr attr;
                        relation_attr_init(&attr, NULL, "*");
                        selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
        }
#line 2585 "yacc_sql.tab.c"
    break;

  case 137: /* subcount_attr: NUMBER  */
#line 917 "yacc_sql.y"
             {
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, "*");
    			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2595 "yacc_sql.tab.c"
    break;

  case 139: /* subattr_list: COMMA ID subattr_list  */
#line 924 "yacc_sql.y"
                            {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
      }
#line 2605 "yacc_sql.tab.c"
    break;

  case 140: /* subattr_list: COMMA ID DOT ID subattr_list  */
#line 929 "yacc_sql.y"
                                   {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
  	  }
#line 2615 "yacc_sql.tab.c"
    break;

  case 141: /* subattr_list: COMMA ID DOT STAR subattr_list  */
#line 934 "yacc_sql.y"
                                     {
      			RelAttr attr;
      			relation_attr_init(&attr, (yyvsp[-3].string), "*");
      			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2625 "yacc_sql.tab.c"
    break;

  case 143: /* subrel_list: COMMA ID subrel_list  */
#line 943 "yacc_sql.y"
                           {
			selects_append_relation(CONTEXT->ssql->sstr.selection.subSelect, (yyvsp[-1].string));
}
#line 2633 "yacc_sql.tab.c"
    break;

  case 144: /* comOp: EQ  */
#line 947 "yacc_sql.y"
         { CONTEXT->comp = EQUAL_TO; }
#line 2639 "yacc_sql.tab.c"
    break;

  case 145: /* comOp: LT  */
#line 948 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2645 "yacc_sql.tab.c"
    break;

  case 146: /* comOp: GT  */
#line 949 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2651 "yacc_sql.tab.c"
    break;

  case 147: /* comOp: LE  */
#line 950 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2657 "yacc_sql.tab.c"
    break;

  case 148: /* comOp: GE  */
#line 951 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2663 "yacc_sql.tab.c"
    break;

  case 149: /* comOp: NE  */
#line 952 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2669 "yacc_sql.tab.c"
    break;

  case 150: /* comOp: IS  */
#line 953 "yacc_sql.y"
         {CONTEXT->comp = EQUAL_IS;}
#line 2675 "yacc_sql.tab.c"
    break;

  case 151: /* comOp: ISNOT  */
#line 954 "yacc_sql.y"
           {CONTEXT->comp = EQUAL_IS_NOT;}
#line 2681 "yacc_sql.tab.c"
    break;

  case 152: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 959 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2690 "yacc_sql.tab.c"
    break;


#line 2694 "yacc_sql.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (scanner, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, scanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 964 "yacc_sql.y"

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, Query *sqls){
	ParserContext context;
	memset(&context, 0, sizeof(context));

	yyscan_t scanner;
	yylex_init_extra(&context, &scanner);
	context.ssql = sqls;
	scan_string(s, scanner);
	int result = yyparse(scanner);
	yylex_destroy(scanner);
	return result;
}
