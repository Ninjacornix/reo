#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E300C
// Address: 0x1e300c - 0x1e316c
void sub_001E300C_0x1e300c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E300C_0x1e300c");
#endif

    switch (ctx->pc) {
        case 0x1e30bcu: goto label_1e30bc;
        case 0x1e3108u: goto label_1e3108;
        case 0x1e3138u: goto label_1e3138;
        default: break;
    }

    ctx->pc = 0x1e300cu;

    // 0x1e300c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e300cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e3010: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e3010u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e3014: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e3014u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e3018: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e3018u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e301c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e301cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e3020: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e3020u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e3024: 0xafc0000c  sw          $zero, 0xC($fp)
    ctx->pc = 0x1e3024u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 0));
    // 0x1e3028: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e3028u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e302c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e302cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e3030: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E3030u;
    {
        const bool branch_taken_0x1e3030 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e3030) {
            ctx->pc = 0x1E3058u;
            goto label_1e3058;
        }
    }
    ctx->pc = 0x1E3038u;
    // 0x1e3038: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e3038u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e303c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e303cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3040: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3040u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3044: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3044u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e3048: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e3048u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e304c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e304cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3050: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3050u;
    {
        const bool branch_taken_0x1e3050 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3050) {
            ctx->pc = 0x1E306Cu;
            goto label_1e306c;
        }
    }
    ctx->pc = 0x1E3058u;
label_1e3058:
    // 0x1e3058: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e3058u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e305c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e305cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3060: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3060u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3064: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1E3064u;
    {
        const bool branch_taken_0x1e3064 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3064) {
            ctx->pc = 0x1E3154u;
            goto label_1e3154;
        }
    }
    ctx->pc = 0x1E306Cu;
label_1e306c:
    // 0x1e306c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e306cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3070: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3070u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3074: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3074u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3078: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3078u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e307c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e307cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e3080: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e3080u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3084: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e3084u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e3088: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e3088u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e308c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e308cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e3090: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3090u;
    {
        const bool branch_taken_0x1e3090 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3090) {
            ctx->pc = 0x1E30ACu;
            goto label_1e30ac;
        }
    }
    ctx->pc = 0x1E3098u;
    // 0x1e3098: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3098u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e309c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e309cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e30a0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e30a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e30a4: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x1E30A4u;
    {
        const bool branch_taken_0x1e30a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e30a4) {
            ctx->pc = 0x1E3154u;
            goto label_1e3154;
        }
    }
    ctx->pc = 0x1E30ACu;
label_1e30ac:
    // 0x1e30ac: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e30acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e30b0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e30b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e30b4: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E30B4u;
    SET_GPR_U32(ctx, 31, 0x1E30BCu);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E30BCu; }
        if (ctx->pc != 0x1E30BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E30BCu; }
        if (ctx->pc != 0x1E30BCu) { return; }
    }
    ctx->pc = 0x1E30BCu;
label_1e30bc:
    // 0x1e30bc: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e30bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1e30c0: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e30c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e30c4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E30C4u;
    {
        const bool branch_taken_0x1e30c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e30c4) {
            ctx->pc = 0x1E30E0u;
            goto label_1e30e0;
        }
    }
    ctx->pc = 0x1E30CCu;
    // 0x1e30cc: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e30ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e30d0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e30d0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e30d4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e30d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e30d8: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1E30D8u;
    {
        const bool branch_taken_0x1e30d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e30d8) {
            ctx->pc = 0x1E3154u;
            goto label_1e3154;
        }
    }
    ctx->pc = 0x1E30E0u;
label_1e30e0:
    // 0x1e30e0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e30e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e30e4: 0x9042061b  lbu         $v0, 0x61B($v0)
    ctx->pc = 0x1e30e4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1563)));
    // 0x1e30e8: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e30e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e30ec: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e30ecu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e30f0: 0x3406a000  ori         $a2, $zero, 0xA000
    ctx->pc = 0x1e30f0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)40960);
    // 0x1e30f4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1e30f4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e30f8: 0x24080007  addiu       $t0, $zero, 0x7
    ctx->pc = 0x1e30f8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1e30fc: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e30fcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3100: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E3100u;
    SET_GPR_U32(ctx, 31, 0x1E3108u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3108u; }
        if (ctx->pc != 0x1E3108u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3108u; }
        if (ctx->pc != 0x1E3108u) { return; }
    }
    ctx->pc = 0x1E3108u;
label_1e3108:
    // 0x1e3108: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3108u;
    {
        const bool branch_taken_0x1e3108 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3108) {
            ctx->pc = 0x1E3124u;
            goto label_1e3124;
        }
    }
    ctx->pc = 0x1E3110u;
    // 0x1e3110: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3110u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3114: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3114u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3118: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3118u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e311c: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E311Cu;
    {
        const bool branch_taken_0x1e311c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e311c) {
            ctx->pc = 0x1E3154u;
            goto label_1e3154;
        }
    }
    ctx->pc = 0x1E3124u;
label_1e3124:
    // 0x1e3124: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e3124u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3128: 0x24050024  addiu       $a1, $zero, 0x24
    ctx->pc = 0x1e3128u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
    // 0x1e312c: 0x8fc60004  lw          $a2, 0x4($fp)
    ctx->pc = 0x1e312cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e3130: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E3130u;
    SET_GPR_U32(ctx, 31, 0x1E3138u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3138u; }
        if (ctx->pc != 0x1E3138u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3138u; }
        if (ctx->pc != 0x1E3138u) { return; }
    }
    ctx->pc = 0x1E3138u;
label_1e3138:
    // 0x1e3138: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e3138u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e313c: 0x9064061b  lbu         $a0, 0x61B($v1)
    ctx->pc = 0x1e313cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1563)));
    // 0x1e3140: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e3140u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e3144: 0xa062061b  sb          $v0, 0x61B($v1)
    ctx->pc = 0x1e3144u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1563), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e3148: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e3148u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e314c: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e314cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e3150: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e3150u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_1e3154:
    // 0x1e3154: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e3154u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3158: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e3158u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e315c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e315cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e3160: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e3160u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e3164: 0x3e00008  jr          $ra
    ctx->pc = 0x1E3164u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E316Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
