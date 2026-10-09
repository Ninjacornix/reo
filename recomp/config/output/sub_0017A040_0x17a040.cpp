#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A040
// Address: 0x17a040 - 0x17a158
void sub_0017A040_0x17a040(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A040_0x17a040");
#endif

    switch (ctx->pc) {
        case 0x17a06cu: goto label_17a06c;
        case 0x17a080u: goto label_17a080;
        case 0x17a10cu: goto label_17a10c;
        case 0x17a120u: goto label_17a120;
        case 0x17a134u: goto label_17a134;
        default: break;
    }

    ctx->pc = 0x17a040u;

    // 0x17a040: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17a040u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17a044: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a044u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a048: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x17a048u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x17a04c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17a04cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a050: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17a050u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17a054: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17a054u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17a058: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x17a058u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a05c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x17a05cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x17a060: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17a060u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17a064: 0xc05e756  jal         func_179D58
    ctx->pc = 0x17A064u;
    SET_GPR_U32(ctx, 31, 0x17A06Cu);
    ctx->pc = 0x17A068u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A064u;
            // 0x17a068: 0xe0982d  daddu       $s3, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A06Cu; }
        if (ctx->pc != 0x17A06Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A06Cu; }
        if (ctx->pc != 0x17A06Cu) { return; }
    }
    ctx->pc = 0x17A06Cu;
label_17a06c:
    // 0x17a06c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x17a06cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a070: 0x12200016  beqz        $s1, . + 4 + (0x16 << 2)
    ctx->pc = 0x17A070u;
    {
        const bool branch_taken_0x17a070 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A074u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A070u;
            // 0x17a074: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a070) {
            ctx->pc = 0x17A0CCu;
            goto label_17a0cc;
        }
    }
    ctx->pc = 0x17A078u;
    // 0x17a078: 0xc05e976  jal         func_17A5D8
    ctx->pc = 0x17A078u;
    SET_GPR_U32(ctx, 31, 0x17A080u);
    ctx->pc = 0x17A5D8u;
    if (runtime->hasFunction(0x17A5D8u)) {
        auto targetFn = runtime->lookupFunction(0x17A5D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A080u; }
        if (ctx->pc != 0x17A080u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A5D8_0x17a5d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A080u; }
        if (ctx->pc != 0x17A080u) { return; }
    }
    ctx->pc = 0x17A080u;
label_17a080:
    // 0x17a080: 0x240300e0  addiu       $v1, $zero, 0xE0
    ctx->pc = 0x17a080u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 224));
    // 0x17a084: 0x14430011  bne         $v0, $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x17A084u;
    {
        const bool branch_taken_0x17a084 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x17A088u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A084u;
            // 0x17a088: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a084) {
            ctx->pc = 0x17A0CCu;
            goto label_17a0cc;
        }
    }
    ctx->pc = 0x17A08Cu;
    // 0x17a08c: 0x2625001c  addiu       $a1, $s1, 0x1C
    ctx->pc = 0x17a08cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 28));
    // 0x17a090: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17a090u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17a094: 0x90a40000  lbu         $a0, 0x0($a1)
    ctx->pc = 0x17a094u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x17a098: 0xae440000  sw          $a0, 0x0($s2)
    ctx->pc = 0x17a098u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 4));
    // 0x17a09c: 0x42100  sll         $a0, $a0, 4
    ctx->pc = 0x17a09cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x17a0a0: 0x90a30001  lbu         $v1, 0x1($a1)
    ctx->pc = 0x17a0a0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
    // 0x17a0a4: 0x31902  srl         $v1, $v1, 4
    ctx->pc = 0x17a0a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 4));
    // 0x17a0a8: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x17a0a8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x17a0ac: 0xae440000  sw          $a0, 0x0($s2)
    ctx->pc = 0x17a0acu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 4));
    // 0x17a0b0: 0x90a30001  lbu         $v1, 0x1($a1)
    ctx->pc = 0x17a0b0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
    // 0x17a0b4: 0xae630000  sw          $v1, 0x0($s3)
    ctx->pc = 0x17a0b4u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x17a0b8: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x17a0b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x17a0bc: 0x90a40002  lbu         $a0, 0x2($a1)
    ctx->pc = 0x17a0bcu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 2)));
    // 0x17a0c0: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x17a0c0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x17a0c4: 0x30630fff  andi        $v1, $v1, 0xFFF
    ctx->pc = 0x17a0c4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4095);
    // 0x17a0c8: 0xae630000  sw          $v1, 0x0($s3)
    ctx->pc = 0x17a0c8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
label_17a0cc:
    // 0x17a0cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a0ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17a0d0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a0d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a0d4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a0d4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a0d8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17a0d8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a0dc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17a0dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17a0e0: 0x3e00008  jr          $ra
    ctx->pc = 0x17A0E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A0E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A0E0u;
            // 0x17a0e4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A06Cu: goto label_17a06c;
            case 0x17A080u: goto label_17a080;
            case 0x17A0CCu: goto label_17a0cc;
            case 0x17A10Cu: goto label_17a10c;
            case 0x17A120u: goto label_17a120;
            case 0x17A134u: goto label_17a134;
            case 0x17A13Cu: goto label_17a13c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A0E8u;
    // 0x17a0e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17a0e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17a0ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a0ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a0f0: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x17a0f0u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x17a0f4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17a0f4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a0f8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17a0f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17a0fc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17a0fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17a100: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17a100u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17a104: 0xc05e756  jal         func_179D58
    ctx->pc = 0x17A104u;
    SET_GPR_U32(ctx, 31, 0x17A10Cu);
    ctx->pc = 0x17A108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A104u;
            // 0x17a108: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A10Cu; }
        if (ctx->pc != 0x17A10Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A10Cu; }
        if (ctx->pc != 0x17A10Cu) { return; }
    }
    ctx->pc = 0x17A10Cu;
label_17a10c:
    // 0x17a10c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x17a10cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a110: 0x1220000a  beqz        $s1, . + 4 + (0xA << 2)
    ctx->pc = 0x17A110u;
    {
        const bool branch_taken_0x17a110 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A114u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A110u;
            // 0x17a114: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a110) {
            ctx->pc = 0x17A13Cu;
            goto label_17a13c;
        }
    }
    ctx->pc = 0x17A118u;
    // 0x17a118: 0xc05e976  jal         func_17A5D8
    ctx->pc = 0x17A118u;
    SET_GPR_U32(ctx, 31, 0x17A120u);
    ctx->pc = 0x17A5D8u;
    if (runtime->hasFunction(0x17A5D8u)) {
        auto targetFn = runtime->lookupFunction(0x17A5D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A120u; }
        if (ctx->pc != 0x17A120u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A5D8_0x17a5d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A120u; }
        if (ctx->pc != 0x17A120u) { return; }
    }
    ctx->pc = 0x17A120u;
label_17a120:
    // 0x17a120: 0x240300e0  addiu       $v1, $zero, 0xE0
    ctx->pc = 0x17a120u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 224));
    // 0x17a124: 0x14430005  bne         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x17A124u;
    {
        const bool branch_taken_0x17a124 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x17A128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A124u;
            // 0x17a128: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a124) {
            ctx->pc = 0x17A13Cu;
            goto label_17a13c;
        }
    }
    ctx->pc = 0x17A12Cu;
    // 0x17a12c: 0xc05e93a  jal         func_17A4E8
    ctx->pc = 0x17A12Cu;
    SET_GPR_U32(ctx, 31, 0x17A134u);
    ctx->pc = 0x17A130u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A12Cu;
            // 0x17a130: 0x9224001f  lbu         $a0, 0x1F($s1) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 31)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A4E8u;
    if (runtime->hasFunction(0x17A4E8u)) {
        auto targetFn = runtime->lookupFunction(0x17A4E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A134u; }
        if (ctx->pc != 0x17A134u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A4E8_0x17a4e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A134u; }
        if (ctx->pc != 0x17A134u) { return; }
    }
    ctx->pc = 0x17A134u;
label_17a134:
    // 0x17a134: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x17a134u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x17a138: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17a138u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_17a13c:
    // 0x17a13c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a13cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17a140: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a140u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a144: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a144u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a148: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17a148u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a14c: 0x3e00008  jr          $ra
    ctx->pc = 0x17A14Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A14Cu;
            // 0x17a150: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A06Cu: goto label_17a06c;
            case 0x17A080u: goto label_17a080;
            case 0x17A0CCu: goto label_17a0cc;
            case 0x17A10Cu: goto label_17a10c;
            case 0x17A120u: goto label_17a120;
            case 0x17A134u: goto label_17a134;
            case 0x17A13Cu: goto label_17a13c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A154u;
    // 0x17a154: 0x0  nop
    ctx->pc = 0x17a154u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
