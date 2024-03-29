//
// Created by justsomedude on 23.03.23.
//

/**
 * MAKE SURE TO LEAVE PROPER CREDIT IF YOU TAKE INSPIRATION FROM THIS CODE
 * Yaroslav Kim SD20-01.
 * You can contact me via telegram @JustSomeDude22
 */

/**
 * General approach for constructing types is the following:
 *
 * Visitor has memory in the form of contextStack, and general tree of function calls.
 * Components of a type are gathered from control points in the contextStack once the stack is populated with the
 * items from a specific visitList, or visitExpr.
 *
 * For example in visitDeclFun we have several control points from which components of a function are gathered.
 * A function is formed from the resulting vectors of StoredType objects and added to map of identifiers.
 *
 * Expressions can be idents, so they are resolved using resolveIdents method.
 *
 * Same logic is seen throughout the code.
 */

#include "MyVisitor.h"
#include <iostream>
#include "Stella/Printer.H"

namespace Stella
{


    void MyVisitor::visitProgram(Program *t) {}                   // abstract class
    void MyVisitor::visitLanguageDecl(LanguageDecl *t) {}         // abstract class
    void MyVisitor::visitExtension(Extension *t) {}               // abstract class
    void MyVisitor::visitDecl(Decl *t) {}                         // abstract class
    void MyVisitor::visitLocalDecl(LocalDecl *t) {}               // abstract class
    void MyVisitor::visitAnnotation(Annotation *t) {}             // abstract class
    void MyVisitor::visitParamDecl(ParamDecl *t) {}               // abstract class
    void MyVisitor::visitReturnType(ReturnType *t) {}             // abstract class
    void MyVisitor::visitThrowType(ThrowType *t) {}               // abstract class
    void MyVisitor::visitType(Type *t) {}                         // abstract class
    void MyVisitor::visitMatchCase(MatchCase *t) {}               // abstract class
    void MyVisitor::visitOptionalTyping(OptionalTyping *t) {}     // abstract class
    void MyVisitor::visitPatternData(PatternData *t) {}           // abstract class
    void MyVisitor::visitExprData(ExprData *t) {}                 // abstract class
    void MyVisitor::visitPattern(Pattern *t) {}                   // abstract class
    void MyVisitor::visitLabelledPattern(LabelledPattern *t) {}   // abstract class
    void MyVisitor::visitBinding(Binding *t) {}                   // abstract class
    void MyVisitor::visitExpr(Expr *t) {}                         // abstract class
    void MyVisitor::visitPatternBinding(PatternBinding *t) {}     // abstract class
    void MyVisitor::visitVariantFieldType(VariantFieldType *t) {} // abstract class
    void MyVisitor::visitRecordFieldType(RecordFieldType *t) {}   // abstract class
    void MyVisitor::visitTyping(Typing *t) {}                     // abstract class

    void MyVisitor::visitAProgram(AProgram *a_program)
    {
        /* Code For AProgram Goes Here */

        std::cout << "Visiting AProgram...\n";

        if (a_program->languagedecl_) a_program->languagedecl_->accept(this);
        if (a_program->listextension_) a_program->listextension_->accept(this);
        if (a_program->listdecl_) a_program->listdecl_->accept(this);
    }

    void MyVisitor::visitLanguageCore(LanguageCore *language_core)
    {
        /* Code For LanguageCore Goes Here */

        std::cout << "Visiting language core...\n";

    }

    void MyVisitor::visitAnExtension(AnExtension *an_extension)
    {
        /* Code For AnExtension Goes Here */

        if (an_extension->listextensionname_) an_extension->listextensionname_->accept(this);

    }

    void MyVisitor::visitDeclFun(DeclFun *decl_fun)
    {
        /* Code For DeclFun Goes Here */

        int startSize = contextStack.size();

        if (decl_fun->listannotation_) decl_fun->listannotation_->accept(this);
        visitStellaIdent(decl_fun->stellaident_);
        std::string ident = contextStack.back().ident;

        increaseScope();

        int paramsStart = contextStack.size();
        if (decl_fun->listparamdecl_) decl_fun->listparamdecl_->accept(this);
        //resolveIdents(paramsStart);
        std::vector <StoredType> params(contextStack.begin() + paramsStart, contextStack.end());

        int returnTypesStart = contextStack.size();
        if (decl_fun->returntype_) decl_fun->returntype_->accept(this);
        //resolveIdents(returnTypesStart);
        std::vector <StoredType> returnTypes(contextStack.begin() + returnTypesStart, contextStack.end());

        if (decl_fun->throwtype_) decl_fun->throwtype_->accept(this);
        if (decl_fun->listdecl_) decl_fun->listdecl_->accept(this);

        int actualReturnsStart = contextStack.size();
        if (decl_fun->expr_) decl_fun->expr_->accept(this);
        resolveIdents(actualReturnsStart);
        std::vector <StoredType> actualReturns(contextStack.begin() + actualReturnsStart, contextStack.end());

        if (!checkMatch(returnTypes, actualReturns)) {
            /*std::cout << actualReturns.size() << '\n';
            for (int i = 0; i < actualReturns.size(); i++) {
                actualReturns[i].print();
            }
            std::cout << returnTypes.size() << '\n';
            for (int i = 0; i < returnTypes.size(); i++) {
                returnTypes[i].print();
            }*/
            std::cout << "Type mismatch between expected and actual in function " << ident << " declaration at "
                      << decl_fun->line_number << ":" << decl_fun->char_number << '\n';
            exit(1);
        }

        decreaseScope();

        StoredType result = ST_FUN;
        result.ident = ident;
        result.argsTypes = params;
        result.returnTypes = returnTypes;
        result.scope = current_scope;

        identMap[result.ident].push_back(result);

        cutContextStack(startSize);

        contextStack.push_back(result);
    }

    void MyVisitor::visitDeclTypeAlias(DeclTypeAlias *decl_type_alias)
    {
        /* Code For DeclTypeAlias Goes Here */

        visitStellaIdent(decl_type_alias->stellaident_);
        if (decl_type_alias->type_) decl_type_alias->type_->accept(this);

    }

    void MyVisitor::visitALocalDecl(ALocalDecl *a_local_decl)
    {
        /* Code For ALocalDecl Goes Here */

        if (a_local_decl->decl_) a_local_decl->decl_->accept(this);

    }

    void MyVisitor::visitInlineAnnotation(InlineAnnotation *inline_annotation)
    {
        /* Code For InlineAnnotation Goes Here */


    }

    void MyVisitor::visitAParamDecl(AParamDecl *a_param_decl)
    {
        /* Code For AParamDecl Goes Here */

        std::cout << "Visiting a Param Decl at " << a_param_decl->line_number << ":" << a_param_decl->char_number << '\n';

        visitStellaIdent(a_param_decl->stellaident_);
        int index_ident = contextStack.size() - 1;

        if (a_param_decl->type_) {
            a_param_decl->type_->accept(this);

            StoredType result = contextStack.back();
            result.ident = contextStack[index_ident].ident;

            identMap[result.ident].push_back(result);

            contextStack.pop_back();
            contextStack.pop_back();

            contextStack.push_back(result);
            std::cout << "Ident tag: " << result.tag << '\n';
        } else {
            std::cout << "Typeless param decl? " << a_param_decl->line_number << ":" << a_param_decl->char_number << '\n';
            exit(1);
        }
    }

    void MyVisitor::visitNoReturnType(NoReturnType *no_return_type)
    {
        /* Code For NoReturnType Goes Here */


    }

    void MyVisitor::visitSomeReturnType(SomeReturnType *some_return_type)
    {
        /* Code For SomeReturnType Goes Here */

        std::cout << "Visiting SomeReturnType at " << some_return_type->line_number << ":" << some_return_type->char_number << '\n';

        if (some_return_type->type_) some_return_type->type_->accept(this);
    }

    void MyVisitor::visitNoThrowType(NoThrowType *no_throw_type)
    {
        /* Code For NoThrowType Goes Here */


    }

    void MyVisitor::visitSomeThrowType(SomeThrowType *some_throw_type)
    {
        /* Code For SomeThrowType Goes Here */

        if (some_throw_type->listtype_) some_throw_type->listtype_->accept(this);

    }

    void MyVisitor::visitSequence(Sequence *sequence)
    {
        /* Code For Sequence Goes Here */

        if (sequence->expr_1)
            sequence->expr_1->accept(this);
        if (sequence->expr_2)
            sequence->expr_2->accept(this);
    }

    void MyVisitor::visitIf(If *if_)
    {
        /* Code For If Goes Here */

        std::cout << "Visiting If at " << if_->line_number << ":" << if_->char_number << '\n';

        increaseScope();

        int startSize = contextStack.size();
        if (if_->expr_1) if_->expr_1->accept(this);
        resolveIdents(startSize);
        std::vector<StoredType> condition(contextStack.begin() + startSize, contextStack.end());

        int returnType1Start = contextStack.size();
        if (if_->expr_2) if_->expr_2->accept(this);
        resolveIdents(returnType1Start);
        std::vector<StoredType> returnType1(contextStack.begin() + returnType1Start, contextStack.end());

        int returnType2Start = contextStack.size();
        if (if_->expr_3) if_->expr_3->accept(this);
        resolveIdents(returnType2Start);
        std::vector<StoredType> returnType2(contextStack.begin() + returnType2Start, contextStack.end());

        if (condition.size() != 1 || condition.back().tag != VisitableTag::tagTypeBool) {
            std::cout << "conditional for if is not a boolean at " << if_->line_number << ":" << if_->char_number << '\n';
            exit(1);
        }

        if (!checkMatch(returnType1, returnType2)) {
            std::cout << "returned types of if do not match at " << if_->line_number << ":" << if_->char_number << '\n';
            exit(1);
        }

        decreaseScope();

        cutContextStack(startSize);

        for (int i = 0; i < returnType1.size(); i++)
            contextStack.push_back(returnType1[i]);
    }

    void MyVisitor::visitLet(Let *let)
    {
        /* Code For Let Goes Here */

        if (let->listpatternbinding_)
            let->listpatternbinding_->accept(this);
        if (let->expr_)
            let->expr_->accept(this);
    }

    void MyVisitor::visitLetRec(LetRec *let_rec)
    {
        /* Code For LetRec Goes Here */

        if (let_rec->listpatternbinding_)
            let_rec->listpatternbinding_->accept(this);
        if (let_rec->expr_)
            let_rec->expr_->accept(this);
    }

    void MyVisitor::visitLessThan(LessThan *less_than)
    {
        /* Code For LessThan Goes Here */

        if (less_than->expr_1) less_than->expr_1->accept(this);
        if (less_than->expr_2) less_than->expr_2->accept(this);

    }

    void MyVisitor::visitLessThanOrEqual(LessThanOrEqual *less_than_or_equal)
    {
        /* Code For LessThanOrEqual Goes Here */

        if (less_than_or_equal->expr_1) less_than_or_equal->expr_1->accept(this);
        if (less_than_or_equal->expr_2) less_than_or_equal->expr_2->accept(this);

    }

    void MyVisitor::visitGreaterThan(GreaterThan *greater_than)
    {
        /* Code For GreaterThan Goes Here */

        if (greater_than->expr_1) greater_than->expr_1->accept(this);
        if (greater_than->expr_2) greater_than->expr_2->accept(this);

    }

    void MyVisitor::visitGreaterThanOrEqual(GreaterThanOrEqual *greater_than_or_equal)
    {
        /* Code For GreaterThanOrEqual Goes Here */

        if (greater_than_or_equal->expr_1) greater_than_or_equal->expr_1->accept(this);
        if (greater_than_or_equal->expr_2) greater_than_or_equal->expr_2->accept(this);

    }

    void MyVisitor::visitEqual(Equal *equal)
    {
        /* Code For Equal Goes Here */

        if (equal->expr_1) equal->expr_1->accept(this);
        if (equal->expr_2) equal->expr_2->accept(this);

    }

    void MyVisitor::visitNotEqual(NotEqual *not_equal)
    {
        /* Code For NotEqual Goes Here */

        if (not_equal->expr_1) not_equal->expr_1->accept(this);
        if (not_equal->expr_2) not_equal->expr_2->accept(this);

    }

    void MyVisitor::visitTypeAsc(TypeAsc *type_asc)
    {
        /* Code For TypeAsc Goes Here */

        if (type_asc->expr_) type_asc->expr_->accept(this);
        if (type_asc->type_) type_asc->type_->accept(this);

    }

    void MyVisitor::visitAbstraction(Abstraction *abstraction)
    {
        /* Code For Abstraction Goes Here */

        std::cout << "Visiting Abstraction at " << abstraction->line_number << ":" << abstraction->char_number << '\n';

        int startSize = contextStack.size();
        if (abstraction->listparamdecl_) abstraction->listparamdecl_->accept(this);
        //resolveIdents(startSize);
        std::vector <StoredType> argsTypes(contextStack.begin() + startSize, contextStack.end());

        int returnTypesStart = contextStack.size();
        if (abstraction->expr_) abstraction->expr_->accept(this);
        resolveIdents(returnTypesStart);
        std::vector <StoredType> returnTypes(contextStack.begin() + returnTypesStart, contextStack.end());

        StoredType result = ST_FUN;
        result.scope = current_scope;
        result.returnTypes = returnTypes;
        result.argsTypes = argsTypes;

        cutContextStack(startSize);

        contextStack.push_back(result);
    }

    void MyVisitor::visitTuple(Tuple *tuple)
    {
        /* Code For Tuple Goes Here */

        std::cout << "Visiting Tuple at " << tuple->line_number << ':' << tuple->char_number << '\n';

        int startSize = contextStack.size();
        if (tuple->listexpr_) tuple->listexpr_->accept(this);
        resolveIdents(startSize);
        std::vector <StoredType> content(contextStack.begin() + startSize, contextStack.end());

        cutContextStack(startSize);

        StoredType result = ST_TUPLE;
        result.contentTypes = content;
        result.scope = current_scope;
        contextStack.push_back(result);
    }

    void MyVisitor::visitRecord(Record *record)
    {
        /* Code For Record Goes Here */

        if (record->listbinding_) record->listbinding_->accept(this);

    }

    void MyVisitor::visitVariant(Variant *variant)
    {
        /* Code For Variant Goes Here */

        visitStellaIdent(variant->stellaident_);
        if (variant->exprdata_) variant->exprdata_->accept(this);

    }

    void MyVisitor::visitMatch(Match *match)
    {
        /* Code For Match Goes Here */

        std::cout << "Visiting Match at " << match->line_number << ":" << match->char_number << '\n';

        increaseScope();

        int startSize = contextStack.size();

        // Toss the match target on top of the stack.
        if (match->expr_) match->expr_->accept(this);
        resolveIdents(startSize);

        int matchesSize = contextStack.size();
        if (match->listmatchcase_) {
            if (match->listmatchcase_->size() > 2) {
                std::cout << "Too many match cases in match declared at line " << match->line_number << ':' << match->char_number << '\n';
                exit(1);
            }
            match->listmatchcase_->accept(this);
        }

        std::vector <StoredType> obtained(contextStack.begin() + matchesSize, contextStack.end());
        StoredType result = collapseTypes(obtained);

        if (result == ST_PLACEHOLDER) {
            std::cout << "Mismatch of items in Match construction at " << match->line_number << ":" << match->char_number << '\n';
            exit(1);
        }

        cutContextStack(startSize);
        contextStack.push_back(result);

        decreaseScope();
    }

    void MyVisitor::visitList(List *list)
    {
        /* Code For List Goes Here */

        if (list->listexpr_) list->listexpr_->accept(this);
    }

    void MyVisitor::visitAdd(Add *add)
    {
        /* Code For Add Goes Here */

        if (add->expr_1) add->expr_1->accept(this);
        if (add->expr_2) add->expr_2->accept(this);

    }

    void MyVisitor::visitSubtract(Subtract *subtract)
    {
        /* Code For Subtract Goes Here */

        if (subtract->expr_1)
            subtract->expr_1->accept(this);
        if (subtract->expr_2)
            subtract->expr_2->accept(this);
    }

    void MyVisitor::visitLogicOr(LogicOr *logic_or)
    {
        /* Code For LogicOr Goes Here */

        if (logic_or->expr_1) logic_or->expr_1->accept(this);
        if (logic_or->expr_2) logic_or->expr_2->accept(this);

    }

    void MyVisitor::visitMultiply(Multiply *multiply)
    {
        /* Code For Multiply Goes Here */

        if (multiply->expr_1) multiply->expr_1->accept(this);
        if (multiply->expr_2) multiply->expr_2->accept(this);

    }

    void MyVisitor::visitDivide(Divide *divide)
    {
        /* Code For Divide Goes Here */

        if (divide->expr_1)
            divide->expr_1->accept(this);
        if (divide->expr_2)
            divide->expr_2->accept(this);
    }

    void MyVisitor::visitLogicAnd(LogicAnd *logic_and)
    {
        /* Code For LogicAnd Goes Here */

        if (logic_and->expr_1) logic_and->expr_1->accept(this);
        if (logic_and->expr_2) logic_and->expr_2->accept(this);

    }

    // FUNCTION CALL #FUNCTIONCALL This is how its called here.
    void MyVisitor::visitApplication(Application *application)
    {
        /* Code For Application Goes Here */
        std::cout << "Visiting Applicaton at " << application->line_number << ":" << application->char_number << '\n';

        increaseScope();

        int startSize = contextStack.size();
        if (application->expr_) application->expr_->accept(this);
        resolveIdents(contextStack.size() - 1);
        StoredType function = contextStack.back();

        std::cout << "Obtained ident: " << function.ident << '\n';

        if (function.tag != VisitableTag::tagTypeFunction) {
            std::cout << "Applying non-function at  " << application->line_number << ":" << application->char_number << '\n';
            exit(1);
        }

        int argListStart = contextStack.size();
        if (application->listexpr_) application->listexpr_->accept(this);
        resolveIdents(argListStart);
        std::vector <StoredType> argStack(contextStack.begin() + argListStart, contextStack.end());

        if (!checkMatch(function.argsTypes, argStack)) {
            std::cout << "Argument type mismatch at application at "
                      << application->line_number << ":"
                      << application->char_number << '\n';
            exit(1);
        }

        decreaseScope();

        cutContextStack(startSize);

        for (int i = 0; i < function.returnTypes.size(); i++) {
            contextStack.push_back(function.returnTypes[i]);
        }
    }

    void MyVisitor::visitConsList(ConsList *cons_list)
    {
        /* Code For ConsList Goes Here */

        if (cons_list->expr_1) cons_list->expr_1->accept(this);
        if (cons_list->expr_2) cons_list->expr_2->accept(this);

    }

    void MyVisitor::visitHead(Head *head)
    {
        /* Code For Head Goes Here */

        if (head->expr_) head->expr_->accept(this);

    }

    void MyVisitor::visitIsEmpty(IsEmpty *is_empty)
    {
        /* Code For IsEmpty Goes Here */

        if (is_empty->expr_) is_empty->expr_->accept(this);

    }

    void MyVisitor::visitTail(Tail *tail)
    {
        /* Code For Tail Goes Here */

        if (tail->expr_) tail->expr_->accept(this);

    }

    void MyVisitor::visitInl(Inl *inl)
    {
        /* Code For Inl Goes Here */

        int startSize = contextStack.size();
        if (inl->expr_)
            inl->expr_->accept(this);
        resolveIdents(startSize);
        std::vector <StoredType> obtained(contextStack.begin() + startSize, contextStack.end());
        if (obtained.size() != 1) {
            std::cout << "Amount of items in Inl is not 1 at " << inl->line_number << ':' << inl->char_number << '\n';
            exit(1);
        }

        StoredType result = ST_SUMTYPE;
        result.contentTypes[0] = obtained.back();

        cutContextStack(startSize);
        contextStack.push_back(result);
    }

    void MyVisitor::visitInr(Inr *inr)
    {
        /* Code For Inr Goes Here */

        int startSize = contextStack.size();
        if (inr->expr_)
            inr->expr_->accept(this);
        resolveIdents(startSize);
        std::vector <StoredType> obtained(contextStack.begin() + startSize, contextStack.end());
        if (obtained.size() != 1) {
            std::cout << "Amount of items in Inl is not 1 at " << inr->line_number << ':' << inr->char_number << '\n';
            exit(1);
        }

        StoredType result = ST_SUMTYPE;
        result.contentTypes[1] = obtained.back();

        cutContextStack(startSize);
        contextStack.push_back(result);
    }

    void MyVisitor::visitSucc(Succ *succ)
    {
        /* Code For Succ Goes Here */

        if (succ->expr_) succ->expr_->accept(this);
        resolveIdents(contextStack.size() - 1);

        if (contextStack.back() != ST_NAT) {
            std::cout << "Expected Nat at " << succ->line_number << ":" << succ->char_number << '\n';
            exit(1);
        }
    }

    void MyVisitor::visitLogicNot(LogicNot *logic_not)
    {
        /* Code For LogicNot Goes Here */

        if (logic_not->expr_) logic_not->expr_->accept(this);

    }

    void MyVisitor::visitPred(Pred *pred)
    {
        /* Code For Pred Goes Here */

        if (pred->expr_) pred->expr_->accept(this);

    }

    void MyVisitor::visitIsZero(IsZero *is_zero)
    {
        /* Code For IsZero Goes Here */

        if (is_zero->expr_) is_zero->expr_->accept(this);

    }

    void MyVisitor::visitFix(Fix *fix)
    {
        /* Code For Fix Goes Here */

        if (fix->expr_) fix->expr_->accept(this);

    }

    void MyVisitor::visitNatRec(NatRec *nat_rec)
    {
        /* Code For NatRec Goes Here */

        std::cout << "Visiting NatRec at " << nat_rec->line_number << ":" << nat_rec->char_number << '\n';

        int startSize = contextStack.size();
        if (nat_rec->expr_1) nat_rec->expr_1->accept(this);
        resolveIdents(startSize);
        std::vector<StoredType> n(contextStack.begin() + startSize, contextStack.end());

        int zStartSize = contextStack.size();
        if (nat_rec->expr_2) nat_rec->expr_2->accept(this);
        resolveIdents(zStartSize);
        std::vector<StoredType> z(contextStack.begin() + zStartSize, contextStack.end());

        int sStartSize = contextStack.size();
        if (nat_rec->expr_3) nat_rec->expr_3->accept(this);
        resolveIdents(sStartSize);
        std::vector<StoredType> s(contextStack.begin() + sStartSize, contextStack.end());

        if (n.size() != 1 || n.back() != ST_NAT) {
            std::cout << "N is not Nat in Nat::rec at " << nat_rec->line_number << ":" << nat_rec->char_number << '\n';
            exit(1);
        }

        StoredType expected = StoredType(VisitableTag::tagTypeFunction,
                                         current_scope,
                                         {ST_NAT},
                                         {
                                            StoredType(VisitableTag::tagTypeFunction,
                                                       current_scope,
                                                       z,
                                                       z)
                                         });

        if (s.size() != 1 || !checkMatch(expected, s.back())) {
            std::cout << "Type mismatch between Z and S in Nat::rec at " << nat_rec->line_number << ":" << nat_rec->char_number << '\n';
            exit(1);
        }

        cutContextStack(startSize);

        for (int i = 0; i < z.size(); i++)
            contextStack.push_back(z[i]);
    }

    void MyVisitor::visitFold(Fold *fold)
    {
        /* Code For Fold Goes Here */

        if (fold->type_) fold->type_->accept(this);
        if (fold->expr_) fold->expr_->accept(this);

    }

    void MyVisitor::visitUnfold(Unfold *unfold)
    {
        /* Code For Unfold Goes Here */

        if (unfold->type_) unfold->type_->accept(this);
        if (unfold->expr_) unfold->expr_->accept(this);

    }

    void MyVisitor::visitDotRecord(DotRecord *dot_record)
    {
        /* Code For DotRecord Goes Here */

        if (dot_record->expr_) dot_record->expr_->accept(this);
        visitStellaIdent(dot_record->stellaident_);

    }

    void MyVisitor::visitDotTuple(DotTuple *dot_tuple)
    {
        /* Code For DotTuple Goes Here */

        int startSize = contextStack.size();
        if (dot_tuple->expr_) dot_tuple->expr_->accept(this);
        resolveIdents(startSize);
        std::vector <StoredType> tuples(contextStack.begin() + startSize, contextStack.end());

        if (tuples.size() != 1) {
            std::cout << "Dot notation without identifier or multiple identifiers at " << dot_tuple->line_number << ":" << dot_tuple->char_number << '\n';
            exit(1);
        }

        int dotSize = contextStack.size();
        visitInteger(dot_tuple->integer_);
        std::vector <StoredType> indexInteger(contextStack.begin() + dotSize, contextStack.end());

        if (indexInteger.size() != 1) {
            std::cout << "No index or multiple index in tuple dot notation at " << dot_tuple->line_number << ':' << dot_tuple->char_number << '\n';
            exit(1);
        }

        int index = indexInteger.back().nat_value;

        if (index < 1 || index > tuples.back().contentTypes.size()) {
            std::cout << "Index out of range for tuple dot notation at " << dot_tuple->line_number << ':' << dot_tuple->char_number << '\n';
            exit(1);
        }

        cutContextStack(startSize);

        StoredType result = tuples.back().contentTypes[index - 1];
        result.scope = current_scope;

        contextStack.push_back(result);
    }

    void MyVisitor::visitConstTrue(ConstTrue *const_true)
    {
        /* Code For ConstTrue Goes Here */

        std::cout << "Visiting ConstTrue at " << const_true->line_number << ":" << const_true->char_number << '\n';

        StoredType result = ST_BOOL;
        result.scope = current_scope;

        contextStack.push_back(result);
    }

    void MyVisitor::visitConstFalse(ConstFalse *const_false)
    {
        /* Code For ConstFalse Goes Here */
        std::cout << "Visiting ConstFalse at " << const_false->line_number << ":" << const_false->char_number << '\n';

        StoredType result = ST_BOOL;
        result.scope = current_scope;

        contextStack.push_back(result);
    }
    
    void MyVisitor::visitConstUnit(ConstUnit *const_unit)
    {
        /* Code For ConstUnit Goes Here */
        std::cout << "Visiting ConstUnit at " << const_unit->line_number << ":" << const_unit->char_number << '\n';

        StoredType result = ST_UNIT;
        result.scope = current_scope;

        contextStack.push_back(result);
    }


    void MyVisitor::visitConstInt(ConstInt *const_int)
    {
        /* Code For ConstInt Goes Here */

        std::cout << "Visiting ConstInt " << const_int->integer_ << " at " << const_int->line_number << ":" << const_int->char_number << '\n';

        visitInteger(const_int->integer_);

    }

    void MyVisitor::visitVar(Var *var)
    {
        /* Code For Var Goes Here */

        visitStellaIdent(var->stellaident_);

    }

    void MyVisitor::visitAPatternBinding(APatternBinding *a_pattern_binding)
    {
        /* Code For APatternBinding Goes Here */

        if (a_pattern_binding->pattern_)
            a_pattern_binding->pattern_->accept(this);
        if (a_pattern_binding->expr_)
            a_pattern_binding->expr_->accept(this);
    }


    void MyVisitor::visitAMatchCase(AMatchCase *a_match_case)
    {
        /* Code For AMatchCase Goes Here */

        std::cout << "Visiting AMatchCase at " << a_match_case->line_number << ":" << a_match_case->char_number << '\n';

        increaseScope();
        // Adding idents to ident map.
        int startSize = contextStack.size();
        if (a_match_case->pattern_) a_match_case->pattern_->accept(this);
        cutContextStack(startSize);

        if (a_match_case->expr_) a_match_case->expr_->accept(this);

        decreaseScope();
    }

    void MyVisitor::visitNoTyping(NoTyping *no_typing)
    {
        /* Code For NoTyping Goes Here */


    }

    void MyVisitor::visitSomeTyping(SomeTyping *some_typing)
    {
        /* Code For SomeTyping Goes Here */

        if (some_typing->type_) some_typing->type_->accept(this);

    }

    void MyVisitor::visitNoPatternData(NoPatternData *no_pattern_data)
    {
        /* Code For NoPatternData Goes Here */


    }

    void MyVisitor::visitSomePatternData(SomePatternData *some_pattern_data)
    {
        /* Code For SomePatternData Goes Here */

        if (some_pattern_data->pattern_) some_pattern_data->pattern_->accept(this);

    }

    void MyVisitor::visitNoExprData(NoExprData *no_expr_data)
    {
        /* Code For NoExprData Goes Here */


    }

    void MyVisitor::visitSomeExprData(SomeExprData *some_expr_data)
    {
        /* Code For SomeExprData Goes Here */

        if (some_expr_data->expr_) some_expr_data->expr_->accept(this);

    }

    void MyVisitor::visitPatternInl(PatternInl *pattern_inl)
    {
        /* Code For PatternInl Goes Here */

        std::cout << "Visiting PatternInl at " << pattern_inl->line_number << ":" << pattern_inl->char_number << '\n';

        int startSize = contextStack.size();
        if (pattern_inl->pattern_)
            pattern_inl->pattern_->accept(this);
        std::vector <StoredType> new_idents(contextStack.begin() + startSize, contextStack.end());

        if (new_idents.size() != 1) {
            std::cout << "Too many idents at PatternInl at " << pattern_inl->line_number << ':' << pattern_inl->char_number << '\n';
            exit(1);
        }

        StoredType *targetSumType = getTopTag(VisitableTag::tagTypeSumType, current_scope - 1);
        StoredType result = targetSumType->contentTypes[0];
        result.scope = current_scope;
        result.ident = new_idents[0].ident;

        identMap[result.ident].push_back(result);

        cutContextStack(startSize);
    }

    void MyVisitor::visitPatternInr(PatternInr *pattern_inr)
    {
        /* Code For PatternInr Goes Here */

        int startSize = contextStack.size();
        if (pattern_inr->pattern_)
            pattern_inr->pattern_->accept(this);
        std::vector <StoredType> new_idents(contextStack.begin() + startSize, contextStack.end());

        if (new_idents.size() != 1) {
            std::cout << "Too many idents at PatternInr at " << pattern_inr->line_number << ':' << pattern_inr->char_number << '\n';
            exit(1);
        }

        StoredType *targetSumType = getTopTag(VisitableTag::tagTypeSumType, current_scope - 1);
        StoredType result = targetSumType->contentTypes[1];
        result.scope = current_scope;
        result.ident = new_idents[0].ident;

        identMap[result.ident].push_back(result);

        cutContextStack(startSize);
    }

    void MyVisitor::visitPatternVariant(PatternVariant *pattern_variant)
    {
        /* Code For PatternVariant Goes Here */

        std::cout << "Visiting PatternVariant at " << pattern_variant->line_number << ':' << pattern_variant->char_number << '\n';

        visitStellaIdent(pattern_variant->stellaident_);
        if (pattern_variant->patterndata_) pattern_variant->patterndata_->accept(this);

    }

    void MyVisitor::visitPatternTuple(PatternTuple *pattern_tuple)
    {
        /* Code For PatternTuple Goes Here */

        if (pattern_tuple->listpattern_) pattern_tuple->listpattern_->accept(this);

    }

    void MyVisitor::visitPatternRecord(PatternRecord *pattern_record)
    {
        /* Code For PatternRecord Goes Here */

        if (pattern_record->listlabelledpattern_) pattern_record->listlabelledpattern_->accept(this);

    }

    void MyVisitor::visitPatternList(PatternList *pattern_list)
    {
        /* Code For PatternList Goes Here */

        if (pattern_list->listpattern_) pattern_list->listpattern_->accept(this);

    }

    void MyVisitor::visitPatternCons(PatternCons *pattern_cons)
    {
        /* Code For PatternCons Goes Here */

        if (pattern_cons->pattern_1) pattern_cons->pattern_1->accept(this);
        if (pattern_cons->pattern_2) pattern_cons->pattern_2->accept(this);

    }

    void MyVisitor::visitPatternFalse(PatternFalse *pattern_false)
    {
        /* Code For PatternFalse Goes Here */


    }

    void MyVisitor::visitPatternTrue(PatternTrue *pattern_true)
    {
        /* Code For PatternTrue Goes Here */


    }

    void MyVisitor::visitPatternUnit(PatternUnit *pattern_unit)
    {
        /* Code For PatternUnit Goes Here */
    }

    void MyVisitor::visitPatternInt(PatternInt *pattern_int)
    {
        /* Code For PatternInt Goes Here */

        visitInteger(pattern_int->integer_);

    }

    void MyVisitor::visitPatternSucc(PatternSucc *pattern_succ)
    {
        /* Code For PatternSucc Goes Here */

        if (pattern_succ->pattern_) pattern_succ->pattern_->accept(this);

    }

    void MyVisitor::visitPatternVar(PatternVar *pattern_var)
    {
        /* Code For PatternVar Goes Here */

        std::cout << "Visiting PatternVar " << pattern_var->stellaident_ << " at " << pattern_var->line_number << ":" << pattern_var->char_number << '\n';

        visitStellaIdent(pattern_var->stellaident_);

    }

    void MyVisitor::visitALabelledPattern(ALabelledPattern *a_labelled_pattern)
    {
        /* Code For ALabelledPattern Goes Here */

        visitStellaIdent(a_labelled_pattern->stellaident_);
        if (a_labelled_pattern->pattern_) a_labelled_pattern->pattern_->accept(this);

    }

    void MyVisitor::visitABinding(ABinding *a_binding)
    {
        /* Code For ABinding Goes Here */

        visitStellaIdent(a_binding->stellaident_);
        if (a_binding->expr_) a_binding->expr_->accept(this);

    }

    void MyVisitor::visitTypeFun(TypeFun *type_fun)
    {
        /* Code For TypeFun Goes Here */

        std::cout << "Visiting TypeFun at " << type_fun->line_number << ":" << type_fun->char_number << '\n';

        int startSize = contextStack.size();
        if (type_fun->listtype_) type_fun->listtype_->accept(this);
        //resolveIdents(startSize);
        std::vector<StoredType> argsTypes(contextStack.begin() + startSize, contextStack.end());

        int returnTypesStart = contextStack.size();
        if (type_fun->type_) type_fun->type_->accept(this);
        //resolveIdents(returnTypesStart);
        std::vector<StoredType> returnTypes(contextStack.begin() + returnTypesStart, contextStack.end());

        StoredType result = ST_FUN;
        result.scope = current_scope;
        result.returnTypes = returnTypes;
        result.argsTypes = argsTypes;

        cutContextStack(startSize);

        contextStack.push_back(result);
    }

    void MyVisitor::visitTypeRec(TypeRec *type_rec)
    {
        /* Code For TypeRec Goes Here */

        visitStellaIdent(type_rec->stellaident_);
        if (type_rec->type_) type_rec->type_->accept(this);

    }

    void MyVisitor::visitTypeSum(TypeSum *type_sum)
    {
        /* Code For TypeSum Goes Here */

        int startSize = contextStack.size();
        if (type_sum->type_1) type_sum->type_1->accept(this);
        if (type_sum->type_2) type_sum->type_2->accept(this);
        std::vector <StoredType> content(contextStack.begin() + startSize, contextStack.end());

        cutContextStack(startSize);

        StoredType result = ST_SUMTYPE;
        result.contentTypes = content;
        result.scope = current_scope;

        contextStack.push_back(result);
    }

    void MyVisitor::visitTypeTuple(TypeTuple *type_tuple)
    {
        /* Code For TypeTuple Goes Here */


        std::cout << "Visiting TypeTuple at " << type_tuple->line_number << ':' << type_tuple->char_number << '\n';

        int startSize = contextStack.size();
        if (type_tuple->listtype_) type_tuple->listtype_->accept(this);
        resolveIdents(startSize);
        std::vector <StoredType> content(contextStack.begin() + startSize, contextStack.end());

        cutContextStack(startSize);

        StoredType result = ST_TUPLE;
        result.contentTypes = content;
        result.scope = current_scope;
        contextStack.push_back(result);
    }

    void MyVisitor::visitTypeRecord(TypeRecord *type_record)
    {
        /* Code For TypeRecord Goes Here */

        if (type_record->listrecordfieldtype_) type_record->listrecordfieldtype_->accept(this);

    }

    void MyVisitor::visitTypeVariant(TypeVariant *type_variant)
    {
        /* Code For TypeVariant Goes Here */

        if (type_variant->listvariantfieldtype_) type_variant->listvariantfieldtype_->accept(this);

    }

    void MyVisitor::visitTypeList(TypeList *type_list)
    {
        /* Code For TypeList Goes Here */

        if (type_list->type_) type_list->type_->accept(this);

    }

    void MyVisitor::visitTypeBool(TypeBool *type_bool)
    {
        /* Code For TypeBool Goes Here */
        std::cout << "Visiting TypeBool at " << type_bool->line_number << ":" << type_bool->char_number << '\n';

        StoredType result = ST_BOOL;
        result.scope = current_scope;

        contextStack.push_back(result);
    }

    void MyVisitor::visitTypeNat(TypeNat *type_nat)
    {
        /* Code For TypeNat Goes Here */

        std::cout << "Visiting TypeNat at " << type_nat->line_number << ":" << type_nat->char_number << '\n';

        StoredType result = ST_NAT;
        result.scope = current_scope;

        contextStack.push_back(result);
    }

    void MyVisitor::visitTypeUnit(TypeUnit *type_unit)
    {
        /* Code For TypeUnit Goes Here */

        std::cout << "Visiting TypeUnit at " << type_unit->line_number << ":" << type_unit->char_number << '\n';

        StoredType result = ST_UNIT;
        result.scope = current_scope;

        contextStack.push_back(result);
    }

    void MyVisitor::visitTypeVar(TypeVar *type_var)
    {
        /* Code For TypeVar Goes Here */

        visitStellaIdent(type_var->stellaident_);

    }

    void MyVisitor::visitAVariantFieldType(AVariantFieldType *a_variant_field_type)
    {
        /* Code For AVariantFieldType Goes Here */

        visitStellaIdent(a_variant_field_type->stellaident_);
        if (a_variant_field_type->optionaltyping_) a_variant_field_type->optionaltyping_->accept(this);

    }

    void MyVisitor::visitARecordFieldType(ARecordFieldType *a_record_field_type)
    {
        /* Code For ARecordFieldType Goes Here */

        visitStellaIdent(a_record_field_type->stellaident_);
        if (a_record_field_type->type_) a_record_field_type->type_->accept(this);

    }

    void MyVisitor::visitATyping(ATyping *a_typing)
    {
        /* Code For ATyping Goes Here */

        if (a_typing->expr_) a_typing->expr_->accept(this);
        if (a_typing->type_) a_typing->type_->accept(this);

    }


    void MyVisitor::visitListStellaIdent(ListStellaIdent *list_stella_ident)
    {
        for (ListStellaIdent::iterator i = list_stella_ident->begin() ; i != list_stella_ident->end() ; ++i)
        {
            visitStellaIdent(*i) ;
        }
    }

    void MyVisitor::visitListExtensionName(ListExtensionName *list_extension_name)
    {
        for (ListExtensionName::iterator i = list_extension_name->begin() ; i != list_extension_name->end() ; ++i)
        {
            visitExtensionName(*i) ;
        }
    }

    void MyVisitor::visitListExtension(ListExtension *list_extension)
    {
        for (ListExtension::iterator i = list_extension->begin() ; i != list_extension->end() ; ++i)
        {
            (*i)->accept(this);
        }
    }

    void MyVisitor::visitListDecl(ListDecl *list_decl)
    {
        std::cout << "Visiting ListDecl of " << list_decl->size() << " elements\n";
        for (ListDecl::iterator i = list_decl->begin() ; i != list_decl->end() ; ++i)
        {
            (*i)->accept(this);
        }
    }

    void MyVisitor::visitListLocalDecl(ListLocalDecl *list_local_decl)
    {
        std::cout << "Visiting LocalListDecl of " << list_local_decl->size() << " elements\n";
        for (ListLocalDecl::iterator i = list_local_decl->begin() ; i != list_local_decl->end() ; ++i)
        {
            (*i)->accept(this);
        }
    }

    void MyVisitor::visitListAnnotation(ListAnnotation *list_annotation)
    {
        std::cout << "Visiting ListAnnotation of " << list_annotation->size() << " elements\n";
        for (ListAnnotation::iterator i = list_annotation->begin() ; i != list_annotation->end() ; ++i)
        {
            (*i)->accept(this);
        }
    }

    void MyVisitor::visitListParamDecl(ListParamDecl *list_param_decl)
    {
        std::cout << "Visiting ListParamDecl of " << list_param_decl->size() << " elements\n";
        for (ListParamDecl::iterator i = list_param_decl->begin() ; i != list_param_decl->end() ; ++i)
        {
            (*i)->accept(this);
        }
    }

    void MyVisitor::visitListExpr(ListExpr *list_expr)
    {
        std::cout << "Visiting ListExpr of " << list_expr->size() << " elements\n";
        for (ListExpr::iterator i = list_expr->begin() ; i != list_expr->end() ; ++i)
        {
            (*i)->accept(this);
        }
    }

    void MyVisitor::visitListPatternBinding(ListPatternBinding *list_pattern_binding)
    {
        for (ListPatternBinding::iterator i = list_pattern_binding->begin(); i != list_pattern_binding->end(); ++i)
        {
            (*i)->accept(this);
        }
    }

    void MyVisitor::visitListMatchCase(ListMatchCase *list_match_case)
    {
        std::cout << "Visiting ListMatchCase of size " << list_match_case->size() << '\n';

        for (ListMatchCase::iterator i = list_match_case->begin() ; i != list_match_case->end() ; ++i)
        {
            (*i)->accept(this);
        }
    }

    void MyVisitor::visitListPattern(ListPattern *list_pattern)
    {
        for (ListPattern::iterator i = list_pattern->begin() ; i != list_pattern->end() ; ++i)
        {
            (*i)->accept(this);
        }
    }

    void MyVisitor::visitListLabelledPattern(ListLabelledPattern *list_labelled_pattern)
    {
        for (ListLabelledPattern::iterator i = list_labelled_pattern->begin() ; i != list_labelled_pattern->end() ; ++i)
        {
            (*i)->accept(this);
        }
    }

    void MyVisitor::visitListBinding(ListBinding *list_binding)
    {
        for (ListBinding::iterator i = list_binding->begin() ; i != list_binding->end() ; ++i)
        {
            (*i)->accept(this);
        }
    }

    void MyVisitor::visitListType(ListType *list_type)
    {
        for (ListType::iterator i = list_type->begin() ; i != list_type->end() ; ++i)
        {
            (*i)->accept(this);
        }
    }

    void MyVisitor::visitListVariantFieldType(ListVariantFieldType *list_variant_field_type)
    {
        for (ListVariantFieldType::iterator i = list_variant_field_type->begin() ; i != list_variant_field_type->end() ; ++i)
        {
            (*i)->accept(this);
        }
    }

    void MyVisitor::visitListRecordFieldType(ListRecordFieldType *list_record_field_type)
    {
        for (ListRecordFieldType::iterator i = list_record_field_type->begin() ; i != list_record_field_type->end() ; ++i)
        {
            (*i)->accept(this);
        }
    }


    void MyVisitor::visitInteger(Integer x)
    {
        /* Code for Integer Goes Here */

        StoredType result = ST_NAT;
        result.scope = current_scope;
        result.nat_value = x;

        contextStack.push_back(result);
    }

    void MyVisitor::visitChar(Char x)
    {
        /* Code for Char Goes Here */

    }

    void MyVisitor::visitDouble(Double x)
    {
        /* Code for Double Goes Here */
    }

    void MyVisitor::visitString(String x)
    {
        /* Code for String Goes Here */
    }

    void MyVisitor::visitIdent(Ident x)
    {
        /* Code for Ident Goes Here */
    }

    void MyVisitor::visitStellaIdent(StellaIdent x)
    {
        /* Code for StellaIdent Goes Here */
        std::cout << "Visiting StellaIdent " << x << '\n';

        StoredType result = ST_IDENT;
        result.scope = current_scope;
        result.ident = x;

        contextStack.push_back(result);
    }

    void MyVisitor::visitExtensionName(ExtensionName x)
    {
        /* Code for ExtensionName Goes Here */
    }


}
