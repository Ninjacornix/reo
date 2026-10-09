#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DB4B8
// Address: 0x1db4b8 - 0x1db598
void sub_001DB4B8_0x1db4b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DB4B8_0x1db4b8");
#endif

    switch (ctx->pc) {
        case 0x1db4e0u: goto label_1db4e0;
        case 0x1db500u: goto label_1db500;
        case 0x1db520u: goto label_1db520;
        case 0x1db53cu: goto label_1db53c;
        default: break;
    }

    ctx->pc = 0x1db4b8u;

    // 0x1db4b8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1db4b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1db4bc: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1db4bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1db4c0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1db4c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1db4c4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1db4c4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db4c8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1db4c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1db4cc: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1db4ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1db4d0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1db4d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db4d4: 0x24052000  addiu       $a1, $zero, 0x2000
    ctx->pc = 0x1db4d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1db4d8: 0xc07c670  jal         func_1F19C0
    ctx->pc = 0x1DB4D8u;
    SET_GPR_U32(ctx, 31, 0x1DB4E0u);
    ctx->pc = 0x1F19C0u;
    if (runtime->hasFunction(0x1F19C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F19C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB4E0u; }
        if (ctx->pc != 0x1DB4E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB4E0u; }
        if (ctx->pc != 0x1DB4E0u) { return; }
    }
    ctx->pc = 0x1DB4E0u;
label_1db4e0:
    // 0x1db4e0: 0x1040001c  beqz        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1DB4E0u;
    {
        const bool branch_taken_0x1db4e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db4e0) {
            ctx->pc = 0x1DB554u;
            goto label_1db554;
        }
    }
    ctx->pc = 0x1DB4E8u;
    // 0x1db4e8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1db4e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db4ec: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1db4ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1db4f0: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x1db4f0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1db4f4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1db4f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db4f8: 0xc07a083  jal         func_1E820C
    ctx->pc = 0x1DB4F8u;
    SET_GPR_U32(ctx, 31, 0x1DB500u);
    ctx->pc = 0x1E820Cu;
    if (runtime->hasFunction(0x1E820Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E820Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB500u; }
        if (ctx->pc != 0x1DB500u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E820C_0x1e820c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB500u; }
        if (ctx->pc != 0x1DB500u) { return; }
    }
    ctx->pc = 0x1DB500u;
label_1db500:
    // 0x1db500: 0xa7c20008  sh          $v0, 0x8($fp)
    ctx->pc = 0x1db500u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x1db504: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1db504u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1db508: 0x34424000  ori         $v0, $v0, 0x4000
    ctx->pc = 0x1db508u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16384);
    // 0x1db50c: 0xa7c20008  sh          $v0, 0x8($fp)
    ctx->pc = 0x1db50cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x1db510: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1db510u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1db514: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1db514u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db518: 0xc07a05f  jal         func_1E817C
    ctx->pc = 0x1DB518u;
    SET_GPR_U32(ctx, 31, 0x1DB520u);
    ctx->pc = 0x1E817Cu;
    if (runtime->hasFunction(0x1E817Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E817Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB520u; }
        if (ctx->pc != 0x1DB520u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E817C_0x1e817c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB520u; }
        if (ctx->pc != 0x1DB520u) { return; }
    }
    ctx->pc = 0x1DB520u;
label_1db520:
    // 0x1db520: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1db520u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db524: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1db524u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db528: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1db528u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1db52c: 0xa4430000  sh          $v1, 0x0($v0)
    ctx->pc = 0x1db52cu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1db530: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1db530u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1db534: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1DB534u;
    SET_GPR_U32(ctx, 31, 0x1DB53Cu);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB53Cu; }
        if (ctx->pc != 0x1DB53Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB53Cu; }
        if (ctx->pc != 0x1DB53Cu) { return; }
    }
    ctx->pc = 0x1DB53Cu;
label_1db53c:
    // 0x1db53c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1db53cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db540: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1db540u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db544: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1db544u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1db548: 0xac43000c  sw          $v1, 0xC($v0)
    ctx->pc = 0x1db548u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 3));
    // 0x1db54c: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1DB54Cu;
    {
        const bool branch_taken_0x1db54c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db54c) {
            ctx->pc = 0x1DB580u;
            goto label_1db580;
        }
    }
    ctx->pc = 0x1DB554u;
label_1db554:
    // 0x1db554: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1db554u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db558: 0x2443002c  addiu       $v1, $v0, 0x2C
    ctx->pc = 0x1db558u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1db55c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1db55cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db560: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1db560u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1db564: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x1db564u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1db568: 0x34424000  ori         $v0, $v0, 0x4000
    ctx->pc = 0x1db568u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16384);
    // 0x1db56c: 0xa4620000  sh          $v0, 0x0($v1)
    ctx->pc = 0x1db56cu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1db570: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1db570u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db574: 0x2443002c  addiu       $v1, $v0, 0x2C
    ctx->pc = 0x1db574u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1db578: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1db578u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1db57c: 0xac62000c  sw          $v0, 0xC($v1)
    ctx->pc = 0x1db57cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 2));
label_1db580:
    // 0x1db580: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1db580u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db584: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1db584u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1db588: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1db588u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1db58c: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1db58cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1db590: 0x3e00008  jr          $ra
    ctx->pc = 0x1DB590u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DB4E0u: goto label_1db4e0;
            case 0x1DB500u: goto label_1db500;
            case 0x1DB520u: goto label_1db520;
            case 0x1DB53Cu: goto label_1db53c;
            case 0x1DB554u: goto label_1db554;
            case 0x1DB580u: goto label_1db580;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DB598u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
