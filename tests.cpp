//
// Created by ignas on 4/12/26.
//
#include <gtest/gtest.h>
#include "eval.h"
#include "token.h"
#include "stack.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

//stack tests

TEST(StackTest, StackCreatedShouldBeEmpty) {
    Stack *s = create_stack(10);
    ASSERT_TRUE(is_empty(s));
}
TEST(StackTest, StackLastPoppedShouldBeEmpty) {
    Stack *s = create_stack(10);
    push(s, 1);
    pop(s);
    ASSERT_TRUE(is_empty(s));
}
TEST(StackTest, StackPushedTopElementShouldBeNewlyPushed) {
    Stack *s = create_stack(10);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    int i = pop(s);
    ASSERT_EQ(i, 3);
}
TEST(StackTest, StackFullShouldReallocate) {
    Stack *s = create_stack(2);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    int i = s->size;
    ASSERT_EQ(i, 4);
}
TEST(StackTest, StackPeekShouldBeNewlyPushed) {
    Stack *s = create_stack(10);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    int i = peek(s);
    ASSERT_EQ(i, 3);
}

//tokenizer tests

TEST(TokenizerTest, TokenizerShouldIdentifyDigitsAndOperators) {
    char * input = "+ 123";
    token t;
    input = GetNextToken(input, &t);
    ASSERT_EQ(t.type, TOK_OPERATOR);
    input = GetNextToken(input, &t);
    ASSERT_EQ(t.type, TOK_OPERAND);
}
//
// TEST(TokenizerTest, TokenizerShouldIdentifyBadOperators) {
//     char * input = "?123";
//     token t;
//     input = GetNextToken(input, &t);
//     ASSERT_EQ(t.type, TOK_OPERATOR);
// }

//eval tests
TEST(EvalTest, EvalPostfixShouldBeFormedCorrectly) {
    char * input = "(1 + 123) * 4";
    char postfix[256];
    toPostfix(input, postfix);
    // std::cout << postfix;
    ASSERT_EQ(strncmp(postfix, "1 123 + 4 *", 11), 0);
}

TEST(EvalTest, EvalPostfixShouldBeParsedCorrectly) {
    char * input = "(1 + 123) * 4";
    char postfix[256];

    // std::cout << postfix;
    ASSERT_EQ(parsePostfix(toPostfix(input, postfix)), 496);
}


