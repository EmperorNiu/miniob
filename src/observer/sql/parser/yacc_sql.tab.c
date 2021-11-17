/* A Bison parser, made by GNU Bison 3.8.2.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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
  YYSYMBOL_TEXT_T = 5,                     /* TEXT_T  */
  YYSYMBOL_ISNOT = 6,                      /* ISNOT  */
  YYSYMBOL_ANULL = 7,                      /* ANULL  */
  YYSYMBOL_NULLABLE = 8,                   /* NULLABLE  */
  YYSYMBOL_NOTNULL = 9,                    /* NOTNULL  */
  YYSYMBOL_CREATE = 10,                    /* CREATE  */
  YYSYMBOL_DROP = 11,                      /* DROP  */
  YYSYMBOL_TABLE = 12,                     /* TABLE  */
  YYSYMBOL_TABLES = 13,                    /* TABLES  */
  YYSYMBOL_INDEX = 14,                     /* INDEX  */
  YYSYMBOL_UNIQUE = 15,                    /* UNIQUE  */
  YYSYMBOL_SELECT = 16,                    /* SELECT  */
  YYSYMBOL_MAX = 17,                       /* MAX  */
  YYSYMBOL_MIN = 18,                       /* MIN  */
  YYSYMBOL_COUNT = 19,                     /* COUNT  */
  YYSYMBOL_AVG = 20,                       /* AVG  */
  YYSYMBOL_DESC = 21,                      /* DESC  */
  YYSYMBOL_ASC = 22,                       /* ASC  */
  YYSYMBOL_ORDERBY = 23,                   /* ORDERBY  */
  YYSYMBOL_GROUPBY = 24,                   /* GROUPBY  */
  YYSYMBOL_SHOW = 25,                      /* SHOW  */
  YYSYMBOL_SYNC = 26,                      /* SYNC  */
  YYSYMBOL_INSERT = 27,                    /* INSERT  */
  YYSYMBOL_DELETE = 28,                    /* DELETE  */
  YYSYMBOL_UPDATE = 29,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 30,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 31,                    /* RBRACE  */
  YYSYMBOL_COMMA = 32,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 33,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 34,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 35,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 36,                     /* INT_T  */
  YYSYMBOL_STRING_T = 37,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 38,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 39,                    /* DATE_T  */
  YYSYMBOL_HELP = 40,                      /* HELP  */
  YYSYMBOL_EXIT = 41,                      /* EXIT  */
  YYSYMBOL_DOT = 42,                       /* DOT  */
  YYSYMBOL_INTO = 43,                      /* INTO  */
  YYSYMBOL_VALUES = 44,                    /* VALUES  */
  YYSYMBOL_FROM = 45,                      /* FROM  */
  YYSYMBOL_WHERE = 46,                     /* WHERE  */
  YYSYMBOL_AND = 47,                       /* AND  */
  YYSYMBOL_SET = 48,                       /* SET  */
  YYSYMBOL_ON = 49,                        /* ON  */
  YYSYMBOL_IN = 50,                        /* IN  */
  YYSYMBOL_NOTIN = 51,                     /* NOTIN  */
  YYSYMBOL_LOAD = 52,                      /* LOAD  */
  YYSYMBOL_DATA = 53,                      /* DATA  */
  YYSYMBOL_INFILE = 54,                    /* INFILE  */
  YYSYMBOL_EQ = 55,                        /* EQ  */
  YYSYMBOL_LT = 56,                        /* LT  */
  YYSYMBOL_GT = 57,                        /* GT  */
  YYSYMBOL_LE = 58,                        /* LE  */
  YYSYMBOL_GE = 59,                        /* GE  */
  YYSYMBOL_NE = 60,                        /* NE  */
  YYSYMBOL_NUMBER = 61,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 62,                     /* FLOAT  */
  YYSYMBOL_DATE = 63,                      /* DATE  */
  YYSYMBOL_ID = 64,                        /* ID  */
  YYSYMBOL_PATH = 65,                      /* PATH  */
  YYSYMBOL_SSS = 66,                       /* SSS  */
  YYSYMBOL_STAR = 67,                      /* STAR  */
  YYSYMBOL_STRING_V = 68,                  /* STRING_V  */
  YYSYMBOL_AGGOP = 69,                     /* AGGOP  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_commands = 71,                  /* commands  */
  YYSYMBOL_command = 72,                   /* command  */
  YYSYMBOL_exit = 73,                      /* exit  */
  YYSYMBOL_help = 74,                      /* help  */
  YYSYMBOL_sync = 75,                      /* sync  */
  YYSYMBOL_begin = 76,                     /* begin  */
  YYSYMBOL_commit = 77,                    /* commit  */
  YYSYMBOL_rollback = 78,                  /* rollback  */
  YYSYMBOL_drop_table = 79,                /* drop_table  */
  YYSYMBOL_show_tables = 80,               /* show_tables  */
  YYSYMBOL_desc_table = 81,                /* desc_table  */
  YYSYMBOL_create_index = 82,              /* create_index  */
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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
#define YYLAST   402

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  164
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  398

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   324


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
      65,    66,    67,    68,    69
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   158,   158,   160,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   184,   189,   194,   200,   206,   212,   218,   224,   230,
     237,   242,   250,   257,   266,   268,   272,   283,   296,   297,
     298,   301,   304,   305,   306,   307,   308,   311,   320,   337,
     339,   345,   347,   352,   355,   358,   362,   366,   372,   382,
     392,   410,   416,   422,   428,   431,   437,   443,   451,   453,
     459,   465,   471,   474,   480,   486,   494,   499,   504,   511,
     516,   521,   526,   531,   534,   536,   543,   550,   559,   561,
     565,   567,   571,   573,   577,   579,   584,   592,   595,   598,
     602,   604,   608,   610,   615,   621,   623,   628,   634,   636,
     640,   642,   647,   668,   688,   708,   730,   751,   772,   791,
     799,   807,   815,   823,   831,   842,   855,   861,   867,   873,
     879,   884,   891,   898,   905,   909,   916,   923,   932,   934,
     940,   946,   952,   955,   961,   967,   975,   980,   985,   990,
     995,   997,  1002,  1007,  1014,  1016,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1031
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
  "TEXT_T", "ISNOT", "ANULL", "NULLABLE", "NOTNULL", "CREATE", "DROP",
  "TABLE", "TABLES", "INDEX", "UNIQUE", "SELECT", "MAX", "MIN", "COUNT",
  "AVG", "DESC", "ASC", "ORDERBY", "GROUPBY", "SHOW", "SYNC", "INSERT",
  "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN",
  "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T",
  "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE", "AND", "SET",
  "ON", "IN", "NOTIN", "LOAD", "DATA", "INFILE", "EQ", "LT", "GT", "LE",
  "GE", "NE", "NUMBER", "FLOAT", "DATE", "ID", "PATH", "SSS", "STAR",
  "STRING_V", "AGGOP", "$accept", "commands", "command", "exit", "help",
  "sync", "begin", "commit", "rollback", "drop_table", "show_tables",
  "desc_table", "create_index", "drop_index", "create_table",
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

#define YYPACT_NINF (-299)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -299,   201,  -299,   231,   129,    99,   -58,    11,    65,    -3,
       7,    43,   128,   169,   170,   179,   180,   131,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,   134,   140,   200,   155,
     156,   193,   194,   195,   202,   -21,  -299,  -299,   186,   230,
     241,  -299,   183,   184,   203,  -299,  -299,  -299,  -299,  -299,
     196,   219,   205,   188,   252,   253,   197,   198,   138,   199,
     204,    63,  -299,   206,  -299,  -299,   213,   212,   207,   208,
     209,   211,   210,  -299,  -299,   -16,    -4,  -299,  -299,  -299,
     229,    -1,    28,   232,   232,   233,   236,    36,   264,   214,
     234,  -299,   240,   108,   246,   215,   248,   217,   248,   218,
     248,   248,   221,   104,  -299,  -299,  -299,   222,   212,    49,
    -299,  -299,  -299,  -299,   119,  -299,   136,   237,  -299,    49,
     266,   209,   256,  -299,  -299,  -299,  -299,  -299,    14,   224,
     259,   137,  -299,   260,  -299,   261,  -299,  -299,   262,   232,
     232,   233,   267,   251,  -299,  -299,   235,   265,   265,  -299,
    -299,  -299,  -299,  -299,  -299,     3,    42,    36,  -299,   212,
     238,   240,   291,  -299,  -299,   239,  -299,   270,   242,   268,
     273,   274,   275,   248,   248,   248,  -299,  -299,  -299,   243,
     272,    49,   277,   130,   281,  -299,  -299,  -299,  -299,  -299,
     269,  -299,   237,   306,   307,  -299,  -299,  -299,   282,   309,
     283,   254,   255,   138,   257,  -299,  -299,  -299,    -8,   284,
     258,   312,   251,   285,   265,   265,    25,   133,   263,  -299,
    -299,  -299,    37,  -299,   317,     0,     8,   292,    17,  -299,
    -299,   271,  -299,   243,  -299,    96,  -299,  -299,  -299,   294,
     322,  -299,  -299,   286,  -299,  -299,   296,   299,   300,   301,
      97,  -299,   287,  -299,  -299,  -299,  -299,   248,   276,   248,
     278,   248,   248,   279,    53,   284,   280,   288,  -299,    49,
    -299,   289,   290,   293,   154,   295,   297,   139,  -299,   298,
    -299,   302,  -299,   303,  -299,  -299,   305,  -299,  -299,   116,
     313,   251,  -299,    59,    78,  -299,   304,  -299,   308,    90,
     117,   315,   315,   316,   248,   248,   248,   310,  -299,  -299,
     318,   319,   311,   319,   314,   320,   319,   319,   321,   146,
    -299,  -299,  -299,   323,   212,  -299,  -299,  -299,   313,   285,
     220,  -299,   324,  -299,   325,  -299,  -299,  -299,   327,   315,
     315,   316,   272,  -299,  -299,   330,   333,   334,   335,   319,
     319,   319,  -299,  -299,  -299,   336,   326,   328,   154,   329,
    -299,  -299,  -299,  -299,    91,    93,   337,    95,   319,   331,
     319,   332,   319,   319,   338,  -299,   339,  -299,   340,  -299,
    -299,   341,   319,   319,   319,  -299,  -299,  -299
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
       0,     0,     0,     0,     0,    84,    79,    83,     0,     0,
       0,    23,     0,     0,     0,    24,    25,    26,    22,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,     0,    29,    28,     0,   108,     0,     0,
       0,     0,     0,    27,    32,     0,     0,    78,    76,    77,
       0,     0,    84,    84,    84,    88,     0,     0,     0,     0,
       0,    47,    34,     0,     0,     0,    68,     0,    68,     0,
      68,    68,     0,     0,    85,    82,    80,     0,   108,     0,
      57,    53,    54,    56,     0,    55,     0,   110,    58,     0,
       0,     0,     0,    46,    42,    43,    44,    45,    38,     0,
       0,     0,    61,     0,    62,     0,    64,    63,     0,    84,
      84,    88,    90,    51,   162,   163,     0,     0,     0,   156,
     157,   158,   159,   160,   161,     0,     0,     0,   109,   108,
       0,    34,     0,    40,    39,     0,    37,     0,     0,     0,
       0,     0,     0,    68,    68,    68,    86,    87,    89,    94,
     100,     0,     0,     0,     0,   121,   123,   114,   112,   119,
     115,   113,   110,     0,     0,    35,    33,    41,     0,     0,
       0,     0,     0,     0,     0,    65,    66,    67,    99,    92,
     102,     0,    51,    49,     0,     0,     0,     0,     0,   111,
      59,   164,    38,    31,     0,     0,     0,     0,     0,    98,
      97,     0,    95,    94,    91,   105,   101,    60,    52,     0,
       0,   122,   124,     0,   116,   120,     0,     0,     0,     0,
     150,   126,     0,   130,   117,    36,    30,    68,     0,    68,
       0,    68,    68,     0,    99,    92,     0,     0,   103,     0,
      48,     0,     0,     0,     0,     0,     0,     0,   128,     0,
      69,     0,    70,     0,    72,    71,     0,    96,    93,   105,
     105,    51,   118,     0,     0,   149,   146,   148,     0,     0,
     150,   150,   150,   154,    68,    68,    68,     0,   106,   104,
       0,   138,     0,   138,     0,     0,   138,   138,     0,     0,
     151,   129,   127,     0,   108,    73,    74,    75,   105,    49,
       0,   131,     0,   132,     0,   147,   134,   133,     0,   150,
     150,   154,   100,   107,    50,     0,     0,     0,     0,   138,
     138,   138,   152,   153,   155,     0,     0,     0,     0,     0,
     135,   136,   137,   125,     0,     0,     0,     0,   138,     0,
     138,     0,   138,   138,     0,   139,     0,   140,     0,   142,
     141,     0,   138,   138,   138,   143,   144,   145
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,   166,   245,   106,  -299,  -299,
    -299,  -299,     2,  -220,  -112,  -299,  -299,  -299,  -299,  -107,
     153,  -299,   -57,   226,  -299,    75,   126,   105,    21,  -299,
    -291,  -118,   178,   216,  -153,  -299,  -299,  -298,    13,  -292,
      31,  -110,  -299
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   132,   102,   176,   208,   138,
     103,    31,   250,   192,   126,    32,    33,    34,    47,   142,
      90,    48,    72,   118,   190,   244,   219,   242,   221,   246,
     278,    98,   168,   127,   195,   262,   263,   341,   308,   288,
     334,   165,    35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     152,   144,   248,   146,   147,   196,    49,   153,   318,   319,
     120,    70,   199,   239,   240,   106,   166,   169,   330,   331,
     332,    71,   173,   174,    50,   343,   107,   108,   346,   347,
     111,   267,   120,   194,   241,   114,   115,   116,   109,   269,
      52,   112,   268,   120,   175,   173,   174,   353,   272,   120,
     270,   203,    53,   198,   201,   194,   120,   362,   363,   273,
      70,   370,   371,   372,   121,   122,   123,   197,    51,   125,
     113,   251,   252,   255,   239,   240,   215,   216,   217,   222,
     385,   320,   387,   226,   389,   390,   121,   122,   123,   253,
     321,   125,   186,   187,   395,   396,   397,   121,   122,   123,
     124,   322,   125,   121,   122,   123,   200,    54,   125,   323,
     121,   122,   123,   133,   254,   125,    41,    42,    43,    44,
     324,   327,   378,   154,   380,   155,   383,    93,   276,   286,
      94,    55,   328,   379,   154,   381,   155,   384,   277,   287,
     154,    39,   155,    40,   134,   135,   136,   137,   276,   286,
     256,   257,   258,   259,   179,   180,   181,   182,   317,   329,
     290,   156,   292,    45,   294,   295,    46,   301,   149,   157,
     158,   150,    56,    57,   159,   160,   161,   162,   163,   164,
     224,   225,    58,    59,    60,   159,   160,   161,   162,   163,
     164,   159,   160,   161,   162,   163,   164,   260,    61,    87,
     261,     2,    88,   311,    62,    89,   312,   335,   336,   337,
     349,     3,     4,   350,    63,   305,   352,     5,   306,    64,
      65,   307,     6,    66,    67,    68,     7,     8,     9,    10,
      11,    73,    69,    74,    12,    13,    14,   355,   356,   357,
     358,    15,    16,    36,    75,    37,    38,    76,    77,    80,
      79,    78,    82,    17,    81,    83,    84,    96,    97,   105,
     110,    85,    86,    91,    70,   117,   119,   128,    92,   129,
      95,    99,   131,   101,   100,   104,   139,   130,   170,   140,
     141,   143,   145,   191,   167,   148,   151,   172,   177,   178,
     189,   183,   184,   185,   206,   194,   220,   227,   211,   193,
     207,   209,   204,   212,   213,   214,   210,   218,   223,   230,
     231,   228,   233,   232,   234,   247,   243,   249,   235,   236,
     266,   238,   245,   271,   279,   280,   282,   264,   281,   283,
     284,   285,   289,   314,   315,   274,   316,   205,   265,   326,
     291,   354,   293,   296,   299,   276,   325,   286,   333,   339,
     298,   340,   300,   302,   303,   359,   360,   304,   361,   309,
     366,   310,   313,   367,   368,   369,   237,   373,   382,   275,
     392,   393,   394,   365,   338,   342,   171,   188,   344,   297,
     229,   376,   364,   202,   345,   348,     0,   351,     0,     0,
     374,     0,   375,   377,     0,   386,   388,     0,     0,     0,
       0,     0,   391
};

static const yytype_int16 yycheck[] =
{
     118,   108,   222,   110,   111,   158,    64,   119,   299,   300,
       7,    32,   165,    21,    22,    31,   126,   129,   310,   311,
     312,    42,     8,     9,    13,   323,    42,    31,   326,   327,
      31,    31,     7,    30,    42,    92,    93,    94,    42,    31,
      43,    42,    42,     7,    30,     8,     9,   338,    31,     7,
      42,   169,    45,   165,   166,    30,     7,   349,   350,    42,
      32,   359,   360,   361,    61,    62,    63,    64,     3,    66,
      42,   224,   225,   226,    21,    22,   183,   184,   185,   191,
     378,   301,   380,   193,   382,   383,    61,    62,    63,    64,
      31,    66,   149,   150,   392,   393,   394,    61,    62,    63,
      64,    42,    66,    61,    62,    63,    64,    64,    66,    31,
      61,    62,    63,     5,   226,    66,    17,    18,    19,    20,
      42,    31,    31,     4,    31,     6,    31,    64,    32,    32,
      67,     3,    42,    42,     4,    42,     6,    42,    42,    42,
       4,    12,     6,    14,    36,    37,    38,    39,    32,    32,
      17,    18,    19,    20,    17,    18,    19,    20,    42,    42,
     267,    42,   269,    64,   271,   272,    67,   279,    64,    50,
      51,    67,     3,     3,    55,    56,    57,    58,    59,    60,
      50,    51,     3,     3,    53,    55,    56,    57,    58,    59,
      60,    55,    56,    57,    58,    59,    60,    64,    64,    61,
      67,     0,    64,    64,    64,    67,    67,   314,   315,   316,
      64,    10,    11,    67,    14,    61,   334,    16,    64,    64,
      64,    67,    21,    30,    30,    30,    25,    26,    27,    28,
      29,    45,    30,     3,    33,    34,    35,    17,    18,    19,
      20,    40,    41,    12,     3,    14,    15,    64,    64,    30,
      54,    48,    64,    52,    49,     3,     3,    44,    46,    49,
      31,    64,    64,    64,    32,    32,    30,     3,    64,    55,
      64,    64,    32,    64,    66,    64,    30,    43,    12,    64,
      32,    64,    64,    32,    47,    64,    64,    31,    64,    30,
      23,    31,    31,    31,     3,    30,    24,    16,    30,    64,
      61,    31,    64,    30,    30,    30,    64,    64,    31,     3,
       3,    42,     3,    31,    31,     3,    32,    32,    64,    64,
       3,    64,    64,    31,    30,     3,    30,    64,    42,    30,
      30,    30,    45,    31,    31,    64,    31,   171,   232,    31,
      64,   339,    64,    64,    64,    32,    42,    32,    32,    31,
     275,    32,    64,    64,    64,    31,    31,    64,    31,    64,
      30,    64,    64,    30,    30,    30,   213,    31,    31,   243,
      31,    31,    31,   352,    64,    64,   131,   151,    64,   274,
     202,   368,   351,   167,    64,    64,    -1,    64,    -1,    -1,
      64,    -1,    64,    64,    -1,    64,    64,    -1,    -1,    -1,
      -1,    -1,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    71,     0,    10,    11,    16,    21,    25,    26,    27,
      28,    29,    33,    34,    35,    40,    41,    52,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    91,    95,    96,    97,   122,    12,    14,    15,    12,
      14,    17,    18,    19,    20,    64,    67,    98,   101,    64,
      13,     3,    43,    45,    64,     3,     3,     3,     3,     3,
      53,    64,    64,    14,    64,    64,    30,    30,    30,    30,
      32,    42,   102,    45,     3,     3,    64,    64,    48,    54,
      30,    49,    64,     3,     3,    64,    64,    61,    64,    67,
     100,    64,    64,    64,    67,    64,    44,    46,   111,    64,
      66,    64,    86,    90,    64,    49,    31,    42,    31,    42,
      31,    31,    42,    42,   102,   102,   102,    32,   103,    30,
       7,    61,    62,    63,    64,    66,    94,   113,     3,    55,
      43,    32,    85,     5,    36,    37,    38,    39,    89,    30,
      64,    32,    99,    64,    99,    64,    99,    99,    64,    64,
      67,    64,   111,    94,     4,     6,    42,    50,    51,    55,
      56,    57,    58,    59,    60,   121,   121,    47,   112,    94,
      12,    86,    31,     8,     9,    30,    87,    64,    30,    17,
      18,    19,    20,    31,    31,    31,   102,   102,   103,    23,
     104,    32,    93,    64,    30,   114,   114,    64,    94,   114,
      64,    94,   113,   111,    64,    85,     3,    61,    88,    31,
      64,    30,    30,    30,    30,    99,    99,    99,    64,   106,
      24,   108,    94,    31,    50,    51,   121,    16,    42,   112,
       3,     3,    31,     3,    31,    64,    64,   100,    64,    21,
      22,    42,   107,    32,   105,    64,   109,     3,    93,    32,
      92,   114,   114,    64,    94,   114,    17,    18,    19,    20,
      64,    67,   115,   116,    64,    87,     3,    31,    42,    31,
      42,    31,    31,    42,    64,   106,    32,    42,   110,    30,
       3,    42,    30,    30,    30,    30,    32,    42,   119,    45,
      99,    64,    99,    64,    99,    99,    64,   107,   105,    64,
      64,    94,    64,    64,    64,    61,    64,    67,   118,    64,
      64,    64,    67,    64,    31,    31,    31,    42,   110,   110,
      93,    31,    42,    31,    42,    42,    31,    31,    42,    42,
     119,   119,   119,    32,   120,    99,    99,    99,    64,    31,
      32,   117,    64,   117,    64,    64,   117,   117,    64,    64,
      67,    64,   111,   110,    92,    17,    18,    19,    20,    31,
      31,    31,   119,   119,   120,   108,    30,    30,    30,    30,
     117,   117,   117,    31,    64,    64,   118,    64,    31,    42,
      31,    42,    31,    31,    42,   117,    64,   117,    64,   117,
     117,    64,    31,    31,    31,   117,   117,   117
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    71,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    82,    83,    84,    85,    85,    86,    86,    87,    87,
      87,    88,    89,    89,    89,    89,    89,    90,    91,    92,
      92,    93,    93,    94,    94,    94,    94,    94,    95,    96,
      97,    98,    98,    98,    98,    98,    98,    98,    99,    99,
      99,    99,    99,    99,    99,    99,   100,   100,   100,   101,
     101,   101,   101,   101,   102,   102,   102,   102,   103,   103,
     104,   104,   105,   105,   106,   106,   106,   107,   107,   107,
     108,   108,   109,   109,   109,   110,   110,   110,   111,   111,
     112,   112,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   114,   115,   115,   115,   115,
     115,   116,   116,   116,   116,   116,   116,   116,   117,   117,
     117,   117,   117,   117,   117,   117,   118,   118,   118,   118,
     119,   119,   119,   119,   120,   120,   121,   121,   121,   121,
     121,   121,   121,   121,   122
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     4,     3,     3,
      10,     9,     4,     8,     0,     3,     6,     3,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,    10,     0,
       6,     0,     3,     1,     1,     1,     1,     1,     5,     8,
       9,     5,     5,     5,     5,     7,     7,     7,     0,     6,
       6,     6,     6,     8,     8,     8,     1,     1,     1,     1,
       4,     2,     4,     1,     0,     3,     5,     5,     0,     3,
       0,     3,     0,     3,     0,     2,     4,     1,     1,     0,
       0,     2,     0,     2,     4,     0,     3,     5,     0,     3,
       0,     3,     3,     3,     3,     3,     5,     5,     7,     3,
       5,     3,     5,     3,     5,     9,     1,     4,     2,     4,
       1,     5,     5,     5,     5,     7,     7,     7,     0,     6,
       6,     6,     6,     8,     8,     8,     1,     3,     1,     1,
       0,     3,     5,     5,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     8
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
#line 184 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1519 "yacc_sql.tab.c"
    break;

  case 22: /* help: HELP SEMICOLON  */
#line 189 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1527 "yacc_sql.tab.c"
    break;

  case 23: /* sync: SYNC SEMICOLON  */
#line 194 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1535 "yacc_sql.tab.c"
    break;

  case 24: /* begin: TRX_BEGIN SEMICOLON  */
#line 200 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1543 "yacc_sql.tab.c"
    break;

  case 25: /* commit: TRX_COMMIT SEMICOLON  */
#line 206 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1551 "yacc_sql.tab.c"
    break;

  case 26: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 212 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1559 "yacc_sql.tab.c"
    break;

  case 27: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 218 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1568 "yacc_sql.tab.c"
    break;

  case 28: /* show_tables: SHOW TABLES SEMICOLON  */
#line 224 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1576 "yacc_sql.tab.c"
    break;

  case 29: /* desc_table: DESC ID SEMICOLON  */
#line 230 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1585 "yacc_sql.tab.c"
    break;

  case 30: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE ID RBRACE SEMICOLON  */
#line 238 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), 1);
		}
#line 1594 "yacc_sql.tab.c"
    break;

  case 31: /* create_index: CREATE INDEX ID ON ID LBRACE ID RBRACE SEMICOLON  */
#line 243 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), 0);
		}
#line 1603 "yacc_sql.tab.c"
    break;

  case 32: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 251 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1612 "yacc_sql.tab.c"
    break;

  case 33: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 258 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1624 "yacc_sql.tab.c"
    break;

  case 35: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 268 "yacc_sql.y"
                                  {    }
#line 1630 "yacc_sql.tab.c"
    break;

  case 36: /* attr_def: ID_get type LBRACE number RBRACE is_nullable  */
#line 273 "yacc_sql.y"
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
#line 1645 "yacc_sql.tab.c"
    break;

  case 37: /* attr_def: ID_get type is_nullable  */
#line 284 "yacc_sql.y"
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
#line 1660 "yacc_sql.tab.c"
    break;

  case 38: /* is_nullable: %empty  */
#line 296 "yacc_sql.y"
        {(yyval.number) = 0;}
#line 1666 "yacc_sql.tab.c"
    break;

  case 39: /* is_nullable: NOTNULL  */
#line 297 "yacc_sql.y"
                  {(yyval.number) = 0;}
#line 1672 "yacc_sql.tab.c"
    break;

  case 40: /* is_nullable: NULLABLE  */
#line 298 "yacc_sql.y"
                   {(yyval.number) = 1;}
#line 1678 "yacc_sql.tab.c"
    break;

  case 41: /* number: NUMBER  */
#line 301 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1684 "yacc_sql.tab.c"
    break;

  case 42: /* type: INT_T  */
#line 304 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1690 "yacc_sql.tab.c"
    break;

  case 43: /* type: STRING_T  */
#line 305 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1696 "yacc_sql.tab.c"
    break;

  case 44: /* type: FLOAT_T  */
#line 306 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1702 "yacc_sql.tab.c"
    break;

  case 45: /* type: DATE_T  */
#line 307 "yacc_sql.y"
                {(yyval.number)=DATES; }
#line 1708 "yacc_sql.tab.c"
    break;

  case 46: /* type: TEXT_T  */
#line 308 "yacc_sql.y"
                {(yyval.number)=TEXTS; }
#line 1714 "yacc_sql.tab.c"
    break;

  case 47: /* ID_get: ID  */
#line 312 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1723 "yacc_sql.tab.c"
    break;

  case 48: /* insert: INSERT INTO ID VALUES LBRACE value value_list RBRACE multi_values SEMICOLON  */
#line 321 "yacc_sql.y"
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
#line 1743 "yacc_sql.tab.c"
    break;

  case 50: /* multi_values: COMMA LBRACE value value_list RBRACE multi_values  */
#line 339 "yacc_sql.y"
                                                       {
  		// CONTEXT->values[CONTEXT->value_length++] = *$3;
  		CONTEXT->insert_num++;
	  }
#line 1752 "yacc_sql.tab.c"
    break;

  case 52: /* value_list: COMMA value value_list  */
#line 347 "yacc_sql.y"
                              { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1760 "yacc_sql.tab.c"
    break;

  case 53: /* value: NUMBER  */
#line 352 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1768 "yacc_sql.tab.c"
    break;

  case 54: /* value: FLOAT  */
#line 355 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1776 "yacc_sql.tab.c"
    break;

  case 55: /* value: SSS  */
#line 358 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1785 "yacc_sql.tab.c"
    break;

  case 56: /* value: DATE  */
#line 362 "yacc_sql.y"
          {
    			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
		value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
    }
#line 1794 "yacc_sql.tab.c"
    break;

  case 57: /* value: ANULL  */
#line 366 "yacc_sql.y"
          {
    		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
    }
#line 1802 "yacc_sql.tab.c"
    break;

  case 58: /* delete: DELETE FROM ID where SEMICOLON  */
#line 373 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1814 "yacc_sql.tab.c"
    break;

  case 59: /* update: UPDATE ID SET ID EQ value where SEMICOLON  */
#line 383 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			Value *value = &CONTEXT->values[0];
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-6].string), (yyvsp[-4].string), value, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1826 "yacc_sql.tab.c"
    break;

  case 60: /* select: SELECT select_attr FROM ID rel_list where order group SEMICOLON  */
#line 393 "yacc_sql.y"
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
#line 1846 "yacc_sql.tab.c"
    break;

  case 61: /* aggregate_attr: MAX LBRACE ID RBRACE aggregate_list  */
#line 410 "yacc_sql.y"
                                        {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 1);
    }
#line 1857 "yacc_sql.tab.c"
    break;

  case 62: /* aggregate_attr: MIN LBRACE ID RBRACE aggregate_list  */
#line 416 "yacc_sql.y"
                                          {
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
    			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 2);
    }
#line 1868 "yacc_sql.tab.c"
    break;

  case 63: /* aggregate_attr: AVG LBRACE ID RBRACE aggregate_list  */
#line 422 "yacc_sql.y"
                                          {
        		RelAttr attr;
        		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
        		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 3);
    }
#line 1879 "yacc_sql.tab.c"
    break;

  case 64: /* aggregate_attr: COUNT LBRACE count_attr RBRACE aggregate_list  */
#line 428 "yacc_sql.y"
                                                    {
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 4);
    }
#line 1887 "yacc_sql.tab.c"
    break;

  case 65: /* aggregate_attr: MAX LBRACE ID DOT ID RBRACE aggregate_list  */
#line 431 "yacc_sql.y"
                                                 {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 1);
    }
#line 1898 "yacc_sql.tab.c"
    break;

  case 66: /* aggregate_attr: MIN LBRACE ID DOT ID RBRACE aggregate_list  */
#line 437 "yacc_sql.y"
                                                 {
    			RelAttr attr;
    			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
    			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 2);
    }
#line 1909 "yacc_sql.tab.c"
    break;

  case 67: /* aggregate_attr: AVG LBRACE ID DOT ID RBRACE aggregate_list  */
#line 443 "yacc_sql.y"
                                                 {
        		RelAttr attr;
        		relation_attr_init(&attr,(yyvsp[-4].string), (yyvsp[-2].string));
        		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 3);
    }
#line 1920 "yacc_sql.tab.c"
    break;

  case 69: /* aggregate_list: COMMA MAX LBRACE ID RBRACE aggregate_list  */
#line 453 "yacc_sql.y"
                                                {
            		RelAttr attr;
            		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
            		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 1);
    }
#line 1931 "yacc_sql.tab.c"
    break;

  case 70: /* aggregate_list: COMMA MIN LBRACE ID RBRACE aggregate_list  */
#line 459 "yacc_sql.y"
                                                {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 2);
    }
#line 1942 "yacc_sql.tab.c"
    break;

  case 71: /* aggregate_list: COMMA AVG LBRACE ID RBRACE aggregate_list  */
#line 465 "yacc_sql.y"
                                                {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 3);
    }
#line 1953 "yacc_sql.tab.c"
    break;

  case 72: /* aggregate_list: COMMA COUNT LBRACE count_attr RBRACE aggregate_list  */
#line 471 "yacc_sql.y"
                                                          {
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 4);
    }
#line 1961 "yacc_sql.tab.c"
    break;

  case 73: /* aggregate_list: COMMA MAX LBRACE ID DOT ID RBRACE aggregate_list  */
#line 474 "yacc_sql.y"
                                                       {
            		RelAttr attr;
            		relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
            		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 1);
    }
#line 1972 "yacc_sql.tab.c"
    break;

  case 74: /* aggregate_list: COMMA MIN LBRACE ID DOT ID RBRACE aggregate_list  */
#line 480 "yacc_sql.y"
                                                       {
                	RelAttr attr;
                	relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
                	selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 2);
    }
#line 1983 "yacc_sql.tab.c"
    break;

  case 75: /* aggregate_list: COMMA AVG LBRACE ID DOT ID RBRACE aggregate_list  */
#line 486 "yacc_sql.y"
                                                       {
                	RelAttr attr;
                	relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
                	selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 3);
    }
#line 1994 "yacc_sql.tab.c"
    break;

  case 76: /* count_attr: ID  */
#line 494 "yacc_sql.y"
       {
    	            	RelAttr attr;
                        relation_attr_init(&attr, NULL, (yyvsp[0].string));
                        selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    }
#line 2004 "yacc_sql.tab.c"
    break;

  case 77: /* count_attr: STAR  */
#line 499 "yacc_sql.y"
           {
        	        RelAttr attr;
                        relation_attr_init(&attr, NULL, "*");
                        selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2014 "yacc_sql.tab.c"
    break;

  case 78: /* count_attr: NUMBER  */
#line 504 "yacc_sql.y"
             {
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, "*");
    			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    }
#line 2024 "yacc_sql.tab.c"
    break;

  case 79: /* select_attr: STAR  */
#line 511 "yacc_sql.y"
         {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2034 "yacc_sql.tab.c"
    break;

  case 80: /* select_attr: ID DOT STAR attr_list  */
#line 516 "yacc_sql.y"
                            {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    }
#line 2044 "yacc_sql.tab.c"
    break;

  case 81: /* select_attr: ID attr_list  */
#line 521 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2054 "yacc_sql.tab.c"
    break;

  case 82: /* select_attr: ID DOT ID attr_list  */
#line 526 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2064 "yacc_sql.tab.c"
    break;

  case 83: /* select_attr: aggregate_attr  */
#line 531 "yacc_sql.y"
                     {
    }
#line 2071 "yacc_sql.tab.c"
    break;

  case 85: /* attr_list: COMMA ID attr_list  */
#line 536 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 2083 "yacc_sql.tab.c"
    break;

  case 86: /* attr_list: COMMA ID DOT ID attr_list  */
#line 543 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2095 "yacc_sql.tab.c"
    break;

  case 87: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 550 "yacc_sql.y"
                                  {
      			RelAttr attr;
      			relation_attr_init(&attr, (yyvsp[-3].string), "*");
      			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
              // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
              // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
    }
#line 2107 "yacc_sql.tab.c"
    break;

  case 89: /* rel_list: COMMA ID rel_list  */
#line 561 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2115 "yacc_sql.tab.c"
    break;

  case 91: /* order: ORDERBY orderby order_list  */
#line 567 "yacc_sql.y"
                                 {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2123 "yacc_sql.tab.c"
    break;

  case 93: /* order_list: COMMA orderby order_list  */
#line 573 "yacc_sql.y"
                              {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2131 "yacc_sql.tab.c"
    break;

  case 95: /* orderby: ID direction  */
#line 579 "yacc_sql.y"
              {
			OrderOp orderOp;
			order_init(&orderOp,CONTEXT->orderDirect,NULL,(yyvsp[-1].string));
			CONTEXT->orderOps[CONTEXT->order_num++]=orderOp;
		}
#line 2141 "yacc_sql.tab.c"
    break;

  case 96: /* orderby: ID DOT ID direction  */
#line 584 "yacc_sql.y"
                                     {
			OrderOp orderOp;
			order_init(&orderOp,CONTEXT->orderDirect,(yyvsp[-3].string),(yyvsp[-1].string));
			CONTEXT->orderOps[CONTEXT->order_num++]=orderOp;
		}
#line 2151 "yacc_sql.tab.c"
    break;

  case 97: /* direction: ASC  */
#line 592 "yacc_sql.y"
        {
    		CONTEXT->orderDirect = ORASC;
    			}
#line 2159 "yacc_sql.tab.c"
    break;

  case 98: /* direction: DESC  */
#line 595 "yacc_sql.y"
           {
		CONTEXT->orderDirect = ORDESC;
			}
#line 2167 "yacc_sql.tab.c"
    break;

  case 99: /* direction: %empty  */
#line 598 "yacc_sql.y"
      {
    		CONTEXT->orderDirect = ORASC;
    }
#line 2175 "yacc_sql.tab.c"
    break;

  case 101: /* group: GROUPBY groupby  */
#line 604 "yacc_sql.y"
                      {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
}
#line 2183 "yacc_sql.tab.c"
    break;

  case 103: /* groupby: ID group_list  */
#line 610 "yacc_sql.y"
               {
	RelAttr attr;
	relation_attr_init(&attr, NULL, (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2193 "yacc_sql.tab.c"
    break;

  case 104: /* groupby: ID DOT ID group_list  */
#line 615 "yacc_sql.y"
                      {
	RelAttr attr;
	relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2203 "yacc_sql.tab.c"
    break;

  case 106: /* group_list: COMMA ID group_list  */
#line 623 "yacc_sql.y"
                     {
	RelAttr attr;
	relation_attr_init(&attr, NULL, (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2213 "yacc_sql.tab.c"
    break;

  case 107: /* group_list: COMMA ID DOT ID group_list  */
#line 628 "yacc_sql.y"
                            {
	RelAttr attr;
	relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2223 "yacc_sql.tab.c"
    break;

  case 109: /* where: WHERE condition condition_list  */
#line 636 "yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2231 "yacc_sql.tab.c"
    break;

  case 111: /* condition_list: AND condition condition_list  */
#line 642 "yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2239 "yacc_sql.tab.c"
    break;

  case 112: /* condition: ID comOp value  */
#line 648 "yacc_sql.y"
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
#line 2264 "yacc_sql.tab.c"
    break;

  case 113: /* condition: value comOp value  */
#line 669 "yacc_sql.y"
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
#line 2288 "yacc_sql.tab.c"
    break;

  case 114: /* condition: ID comOp ID  */
#line 689 "yacc_sql.y"
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
#line 2312 "yacc_sql.tab.c"
    break;

  case 115: /* condition: value comOp ID  */
#line 709 "yacc_sql.y"
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
#line 2338 "yacc_sql.tab.c"
    break;

  case 116: /* condition: ID DOT ID comOp value  */
#line 731 "yacc_sql.y"
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
#line 2363 "yacc_sql.tab.c"
    break;

  case 117: /* condition: value comOp ID DOT ID  */
#line 752 "yacc_sql.y"
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
#line 2388 "yacc_sql.tab.c"
    break;

  case 118: /* condition: ID DOT ID comOp ID DOT ID  */
#line 773 "yacc_sql.y"
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
#line 2411 "yacc_sql.tab.c"
    break;

  case 119: /* condition: ID comOp subselect  */
#line 791 "yacc_sql.y"
                         {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2424 "yacc_sql.tab.c"
    break;

  case 120: /* condition: ID DOT ID comOp subselect  */
#line 799 "yacc_sql.y"
                                {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2437 "yacc_sql.tab.c"
    break;

  case 121: /* condition: ID IN subselect  */
#line 807 "yacc_sql.y"
                      {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, EQUAL_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2450 "yacc_sql.tab.c"
    break;

  case 122: /* condition: ID DOT ID IN subselect  */
#line 815 "yacc_sql.y"
                             {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, EQUAL_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2463 "yacc_sql.tab.c"
    break;

  case 123: /* condition: ID NOTIN subselect  */
#line 823 "yacc_sql.y"
                         {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, NOT_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2476 "yacc_sql.tab.c"
    break;

  case 124: /* condition: ID DOT ID NOTIN subselect  */
#line 831 "yacc_sql.y"
                                {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, NOT_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2489 "yacc_sql.tab.c"
    break;

  case 125: /* subselect: LBRACE SELECT subselect_attr FROM ID subrel_list where group RBRACE  */
#line 843 "yacc_sql.y"
                {

			selects_append_relation(CONTEXT->ssql->sstr.selection.subSelect, (yyvsp[-4].string));
			selects_append_conditions(CONTEXT->ssql->sstr.selection.subSelect, CONTEXT->conditions, CONTEXT->condition_length);
			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 2504 "yacc_sql.tab.c"
    break;

  case 126: /* subselect_attr: STAR  */
#line 855 "yacc_sql.y"
         {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
		}
#line 2515 "yacc_sql.tab.c"
    break;

  case 127: /* subselect_attr: ID DOT STAR subattr_list  */
#line 861 "yacc_sql.y"
                               {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2526 "yacc_sql.tab.c"
    break;

  case 128: /* subselect_attr: ID subattr_list  */
#line 867 "yacc_sql.y"
                      {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
		}
#line 2537 "yacc_sql.tab.c"
    break;

  case 129: /* subselect_attr: ID DOT ID subattr_list  */
#line 873 "yacc_sql.y"
                                 {
	sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
	}
#line 2548 "yacc_sql.tab.c"
    break;

  case 130: /* subselect_attr: subaggregate_attr  */
#line 879 "yacc_sql.y"
                        {
    }
#line 2555 "yacc_sql.tab.c"
    break;

  case 131: /* subaggregate_attr: MAX LBRACE ID RBRACE subaggregate_list  */
#line 884 "yacc_sql.y"
                                           {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 1);
    }
#line 2567 "yacc_sql.tab.c"
    break;

  case 132: /* subaggregate_attr: MIN LBRACE ID RBRACE subaggregate_list  */
#line 891 "yacc_sql.y"
                                             {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
    			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 2);
    }
#line 2579 "yacc_sql.tab.c"
    break;

  case 133: /* subaggregate_attr: AVG LBRACE ID RBRACE subaggregate_list  */
#line 898 "yacc_sql.y"
                                             {
	sub_selects_init(&CONTEXT->ssql->sstr.selection);
        		RelAttr attr;
        		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
        		selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 3);
    }
#line 2591 "yacc_sql.tab.c"
    break;

  case 134: /* subaggregate_attr: COUNT LBRACE subcount_attr RBRACE subaggregate_list  */
#line 905 "yacc_sql.y"
                                                          {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 4);
    }
#line 2600 "yacc_sql.tab.c"
    break;

  case 135: /* subaggregate_attr: MAX LBRACE ID DOT ID RBRACE subaggregate_list  */
#line 909 "yacc_sql.y"
                                                    {
          sub_selects_init(&CONTEXT->ssql->sstr.selection);
      			RelAttr attr;
      			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
      			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
          			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 1);
          }
#line 2612 "yacc_sql.tab.c"
    break;

  case 136: /* subaggregate_attr: MIN LBRACE ID DOT ID RBRACE subaggregate_list  */
#line 916 "yacc_sql.y"
                                                    {
	  sub_selects_init(&CONTEXT->ssql->sstr.selection);
				RelAttr attr;
				relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
				selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
				selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 2);
	  }
#line 2624 "yacc_sql.tab.c"
    break;

  case 137: /* subaggregate_attr: AVG LBRACE ID DOT ID RBRACE subaggregate_list  */
#line 923 "yacc_sql.y"
                                                    {
	sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
				selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 3);
	}
#line 2636 "yacc_sql.tab.c"
    break;

  case 139: /* subaggregate_list: COMMA MAX LBRACE ID RBRACE subaggregate_list  */
#line 934 "yacc_sql.y"
                                                   {
            		RelAttr attr;
            		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
            		selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 1);
    }
#line 2647 "yacc_sql.tab.c"
    break;

  case 140: /* subaggregate_list: COMMA MIN LBRACE ID RBRACE subaggregate_list  */
#line 940 "yacc_sql.y"
                                                   {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 2);
    }
#line 2658 "yacc_sql.tab.c"
    break;

  case 141: /* subaggregate_list: COMMA AVG LBRACE ID RBRACE subaggregate_list  */
#line 946 "yacc_sql.y"
                                                   {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 3);
    }
#line 2669 "yacc_sql.tab.c"
    break;

  case 142: /* subaggregate_list: COMMA COUNT LBRACE subcount_attr RBRACE subaggregate_list  */
#line 952 "yacc_sql.y"
                                                                {
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 4);
    }
#line 2677 "yacc_sql.tab.c"
    break;

  case 143: /* subaggregate_list: COMMA MAX LBRACE ID DOT ID RBRACE subaggregate_list  */
#line 955 "yacc_sql.y"
                                                          {
            		RelAttr attr;
            		relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
            		selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 1);
    }
#line 2688 "yacc_sql.tab.c"
    break;

  case 144: /* subaggregate_list: COMMA MIN LBRACE ID DOT ID RBRACE subaggregate_list  */
#line 961 "yacc_sql.y"
                                                          {
                	RelAttr attr;
                	relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
                	selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 2);
    }
#line 2699 "yacc_sql.tab.c"
    break;

  case 145: /* subaggregate_list: COMMA AVG LBRACE ID DOT ID RBRACE subaggregate_list  */
#line 967 "yacc_sql.y"
                                                          {
                	RelAttr attr;
                	relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
                	selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 3);
    }
#line 2710 "yacc_sql.tab.c"
    break;

  case 146: /* subcount_attr: ID  */
#line 975 "yacc_sql.y"
       {
    	            	RelAttr attr;
                        relation_attr_init(&attr, NULL, (yyvsp[0].string));
                        selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2720 "yacc_sql.tab.c"
    break;

  case 147: /* subcount_attr: ID DOT ID  */
#line 980 "yacc_sql.y"
               {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2730 "yacc_sql.tab.c"
    break;

  case 148: /* subcount_attr: STAR  */
#line 985 "yacc_sql.y"
           {
        	        RelAttr attr;
                        relation_attr_init(&attr, NULL, "*");
                        selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
        }
#line 2740 "yacc_sql.tab.c"
    break;

  case 149: /* subcount_attr: NUMBER  */
#line 990 "yacc_sql.y"
             {
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, "*");
    			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2750 "yacc_sql.tab.c"
    break;

  case 151: /* subattr_list: COMMA ID subattr_list  */
#line 997 "yacc_sql.y"
                            {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
      }
#line 2760 "yacc_sql.tab.c"
    break;

  case 152: /* subattr_list: COMMA ID DOT ID subattr_list  */
#line 1002 "yacc_sql.y"
                                   {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
  	  }
#line 2770 "yacc_sql.tab.c"
    break;

  case 153: /* subattr_list: COMMA ID DOT STAR subattr_list  */
#line 1007 "yacc_sql.y"
                                     {
      			RelAttr attr;
      			relation_attr_init(&attr, (yyvsp[-3].string), "*");
      			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2780 "yacc_sql.tab.c"
    break;

  case 155: /* subrel_list: COMMA ID subrel_list  */
#line 1016 "yacc_sql.y"
                           {
			selects_append_relation(CONTEXT->ssql->sstr.selection.subSelect, (yyvsp[-1].string));
}
#line 2788 "yacc_sql.tab.c"
    break;

  case 156: /* comOp: EQ  */
#line 1020 "yacc_sql.y"
         { CONTEXT->comp = EQUAL_TO; }
#line 2794 "yacc_sql.tab.c"
    break;

  case 157: /* comOp: LT  */
#line 1021 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2800 "yacc_sql.tab.c"
    break;

  case 158: /* comOp: GT  */
#line 1022 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2806 "yacc_sql.tab.c"
    break;

  case 159: /* comOp: LE  */
#line 1023 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2812 "yacc_sql.tab.c"
    break;

  case 160: /* comOp: GE  */
#line 1024 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2818 "yacc_sql.tab.c"
    break;

  case 161: /* comOp: NE  */
#line 1025 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2824 "yacc_sql.tab.c"
    break;

  case 162: /* comOp: IS  */
#line 1026 "yacc_sql.y"
         {CONTEXT->comp = EQUAL_IS;}
#line 2830 "yacc_sql.tab.c"
    break;

  case 163: /* comOp: ISNOT  */
#line 1027 "yacc_sql.y"
           {CONTEXT->comp = EQUAL_IS_NOT;}
#line 2836 "yacc_sql.tab.c"
    break;

  case 164: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 1032 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2845 "yacc_sql.tab.c"
    break;


#line 2849 "yacc_sql.tab.c"

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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

#line 1037 "yacc_sql.y"

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
