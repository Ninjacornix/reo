#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A228
// Address: 0x17a228 - 0x17a294
void sub_0017A228_0x17a228(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A228_0x17a228");
#endif

    switch (ctx->pc) {
        case 0x17a24cu: goto label_17a24c;
        case 0x17a264u: goto label_17a264;
        default: break;
    }

    ctx->pc = 0x17a228u;

    // 0x17a228: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17a228u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17a22c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a22cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a230: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x17a230u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x17a234: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17a234u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a238: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17a238u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17a23c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17a23cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17a240: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17a240u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17a244: 0xc05e756  jal         func_179D58
    ctx->pc = 0x17A244u;
    SET_GPR_U32(ctx, 31, 0x17A24Cu);
    ctx->pc = 0x17A248u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A244u;
            // 0x17a248: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A24Cu; }
        if (ctx->pc != 0x17A24Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A24Cu; }
        if (ctx->pc != 0x17A24Cu) { return; }
    }
    ctx->pc = 0x17A24Cu;
label_17a24c:
    // 0x17a24c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x17a24cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a250: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17a250u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a254: 0x12200009  beqz        $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x17A254u;
    {
        const bool branch_taken_0x17a254 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A258u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A254u;
            // 0x17a258: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a254) {
            ctx->pc = 0x17A27Cu;
            goto label_17a27c;
        }
    }
    ctx->pc = 0x17A25Cu;
    // 0x17a25c: 0xc05e966  jal         func_17A598
    ctx->pc = 0x17A25Cu;
    SET_GPR_U32(ctx, 31, 0x17A264u);
    ctx->pc = 0x17A598u;
    if (runtime->hasFunction(0x17A598u)) {
        auto targetFn = runtime->lookupFunction(0x17A598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A264u; }
        if (ctx->pc != 0x17A264u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A598_0x17a598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A264u; }
        if (ctx->pc != 0x17A264u) { return; }
    }
    ctx->pc = 0x17A264u;
label_17a264:
    // 0x17a264: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17A264u;
    {
        const bool branch_taken_0x17a264 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A264u;
            // 0x17a268: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a264) {
            ctx->pc = 0x17A280u;
            goto label_17a280;
        }
    }
    ctx->pc = 0x17A26Cu;
    // 0x17a26c: 0x92230023  lbu         $v1, 0x23($s1)
    ctx->pc = 0x17a26cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 35)));
    // 0x17a270: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17a270u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17a274: 0x30630001  andi        $v1, $v1, 0x1
    ctx->pc = 0x17a274u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x17a278: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x17a278u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_17a27c:
    // 0x17a27c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a27cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17a280:
    // 0x17a280: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a280u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a284: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a284u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a288: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17a288u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a28c: 0x3e00008  jr          $ra
    ctx->pc = 0x17A28Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A28Cu;
            // 0x17a290: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A24Cu: goto label_17a24c;
            case 0x17A264u: goto label_17a264;
            case 0x17A27Cu: goto label_17a27c;
            case 0x17A280u: goto label_17a280;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A294u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
