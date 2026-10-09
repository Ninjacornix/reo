#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00168490
// Address: 0x168490 - 0x168578
void sub_00168490_0x168490(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00168490_0x168490");
#endif

    switch (ctx->pc) {
        case 0x1684ccu: goto label_1684cc;
        case 0x1684ecu: goto label_1684ec;
        case 0x16850cu: goto label_16850c;
        case 0x16854cu: goto label_16854c;
        default: break;
    }

    ctx->pc = 0x168490u;

    // 0x168490: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x168490u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x168494: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x168494u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x168498: 0xc0b02d  daddu       $s6, $a2, $zero
    ctx->pc = 0x168498u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16849c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16849cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1684a0: 0x3c060001  lui         $a2, 0x1
    ctx->pc = 0x1684a0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)1 << 16));
    // 0x1684a4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1684a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1684a8: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1684a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1684ac: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1684acu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1684b0: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x1684b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x1684b4: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x1684b4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1684b8: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x1684b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x1684bc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1684bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1684c0: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1684c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1684c4: 0xc05a208  jal         func_168820
    ctx->pc = 0x1684C4u;
    SET_GPR_U32(ctx, 31, 0x1684CCu);
    ctx->pc = 0x1684C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1684C4u;
            // 0x1684c8: 0xaec00000  sw          $zero, 0x0($s6) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 22), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168820u;
    if (runtime->hasFunction(0x168820u)) {
        auto targetFn = runtime->lookupFunction(0x168820u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1684CCu; }
        if (ctx->pc != 0x1684CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168820_0x168820(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1684CCu; }
        if (ctx->pc != 0x1684CCu) { return; }
    }
    ctx->pc = 0x1684CCu;
label_1684cc:
    // 0x1684cc: 0x3c060001  lui         $a2, 0x1
    ctx->pc = 0x1684ccu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)1 << 16));
    // 0x1684d0: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1684d0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1684d4: 0x2339023  subu        $s2, $s1, $s3
    ctx->pc = 0x1684d4u;
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 19)));
    // 0x1684d8: 0x26240001  addiu       $a0, $s1, 0x1
    ctx->pc = 0x1684d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1684dc: 0x1220001c  beqz        $s1, . + 4 + (0x1C << 2)
    ctx->pc = 0x1684DCu;
    {
        const bool branch_taken_0x1684dc = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x1684E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1684DCu;
            // 0x1684e0: 0x292a823  subu        $s5, $s4, $s2 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)SUB32(GPR_U32(ctx, 20), GPR_U32(ctx, 18)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1684dc) {
            ctx->pc = 0x168550u;
            goto label_168550;
        }
    }
    ctx->pc = 0x1684E4u;
    // 0x1684e4: 0xc05a208  jal         func_168820
    ctx->pc = 0x1684E4u;
    SET_GPR_U32(ctx, 31, 0x1684ECu);
    ctx->pc = 0x1684E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1684E4u;
            // 0x1684e8: 0x26a5ffff  addiu       $a1, $s5, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168820u;
    if (runtime->hasFunction(0x168820u)) {
        auto targetFn = runtime->lookupFunction(0x168820u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1684ECu; }
        if (ctx->pc != 0x1684ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168820_0x168820(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1684ECu; }
        if (ctx->pc != 0x1684ECu) { return; }
    }
    ctx->pc = 0x1684ECu;
label_1684ec:
    // 0x1684ec: 0x3c060001  lui         $a2, 0x1
    ctx->pc = 0x1684ecu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)1 << 16));
    // 0x1684f0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1684f0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1684f4: 0x2131823  subu        $v1, $s0, $s3
    ctx->pc = 0x1684f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
    // 0x1684f8: 0x26040001  addiu       $a0, $s0, 0x1
    ctx->pc = 0x1684f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1684fc: 0x12000014  beqz        $s0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1684FCu;
    {
        const bool branch_taken_0x1684fc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x168500u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1684FCu;
            // 0x168500: 0x2832823  subu        $a1, $s4, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 20), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1684fc) {
            ctx->pc = 0x168550u;
            goto label_168550;
        }
    }
    ctx->pc = 0x168504u;
    // 0x168504: 0xc05a208  jal         func_168820
    ctx->pc = 0x168504u;
    SET_GPR_U32(ctx, 31, 0x16850Cu);
    ctx->pc = 0x168508u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168504u;
            // 0x168508: 0x24a5ffff  addiu       $a1, $a1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168820u;
    if (runtime->hasFunction(0x168820u)) {
        auto targetFn = runtime->lookupFunction(0x168820u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16850Cu; }
        if (ctx->pc != 0x16850Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168820_0x168820(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16850Cu; }
        if (ctx->pc != 0x16850Cu) { return; }
    }
    ctx->pc = 0x16850Cu;
label_16850c:
    // 0x16850c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x16850cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168510: 0x1060000f  beqz        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x168510u;
    {
        const bool branch_taken_0x168510 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x168514u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168510u;
            // 0x168514: 0x702023  subu        $a0, $v1, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168510) {
            ctx->pc = 0x168550u;
            goto label_168550;
        }
    }
    ctx->pc = 0x168518u;
    // 0x168518: 0x2118023  subu        $s0, $s0, $s1
    ctx->pc = 0x168518u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x16851c: 0x1604000c  bne         $s0, $a0, . + 4 + (0xC << 2)
    ctx->pc = 0x16851Cu;
    {
        const bool branch_taken_0x16851c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 4));
        ctx->pc = 0x168520u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16851Cu;
            // 0x168520: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16851c) {
            ctx->pc = 0x168550u;
            goto label_168550;
        }
    }
    ctx->pc = 0x168524u;
    // 0x168524: 0x250001a  div         $zero, $s2, $s0
    ctx->pc = 0x168524u;
    { int32_t divisor = GPR_S32(ctx, 16);    int32_t dividend = GPR_S32(ctx, 18);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x168528: 0x52000001  beql        $s0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x168528u;
    {
        const bool branch_taken_0x168528 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x168528) {
            ctx->pc = 0x16852Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x168528u;
            // 0x16852c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x168530u;
            goto label_168530;
        }
    }
    ctx->pc = 0x168530u;
label_168530:
    // 0x168530: 0x1810  mfhi        $v1
    ctx->pc = 0x168530u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x168534: 0x54600007  bnel        $v1, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x168534u;
    {
        const bool branch_taken_0x168534 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x168534) {
            ctx->pc = 0x168538u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x168534u;
            // 0x168538: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x168554u;
            goto label_168554;
        }
    }
    ctx->pc = 0x16853Cu;
    // 0x16853c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16853cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168540: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x168540u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168544: 0xc05a15e  jal         func_168578
    ctx->pc = 0x168544u;
    SET_GPR_U32(ctx, 31, 0x16854Cu);
    ctx->pc = 0x168548u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168544u;
            // 0x168548: 0x2c0302d  daddu       $a2, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168578u;
    if (runtime->hasFunction(0x168578u)) {
        auto targetFn = runtime->lookupFunction(0x168578u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16854Cu; }
        if (ctx->pc != 0x16854Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168578_0x168578(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16854Cu; }
        if (ctx->pc != 0x16854Cu) { return; }
    }
    ctx->pc = 0x16854Cu;
label_16854c:
    // 0x16854c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x16854cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_168550:
    // 0x168550: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x168550u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_168554:
    // 0x168554: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x168554u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x168558: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x168558u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16855c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16855cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x168560: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x168560u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x168564: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x168564u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x168568: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x168568u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16856c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x16856cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x168570: 0x3e00008  jr          $ra
    ctx->pc = 0x168570u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x168574u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168570u;
            // 0x168574: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1684CCu: goto label_1684cc;
            case 0x1684ECu: goto label_1684ec;
            case 0x16850Cu: goto label_16850c;
            case 0x168530u: goto label_168530;
            case 0x16854Cu: goto label_16854c;
            case 0x168550u: goto label_168550;
            case 0x168554u: goto label_168554;
            default: break;
        }
        return;
    }
    ctx->pc = 0x168578u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
