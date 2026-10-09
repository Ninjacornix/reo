#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A158
// Address: 0x17a158 - 0x17a4e8
void sub_0017A158_0x17a158(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A158_0x17a158");
#endif

    switch (ctx->pc) {
        case 0x17a17cu: goto label_17a17c;
        case 0x17a194u: goto label_17a194;
        case 0x17a1e4u: goto label_17a1e4;
        case 0x17a1fcu: goto label_17a1fc;
        case 0x17a24cu: goto label_17a24c;
        case 0x17a264u: goto label_17a264;
        case 0x17a2bcu: goto label_17a2bc;
        case 0x17a2d4u: goto label_17a2d4;
        case 0x17a32cu: goto label_17a32c;
        case 0x17a344u: goto label_17a344;
        case 0x17a394u: goto label_17a394;
        case 0x17a3acu: goto label_17a3ac;
        case 0x17a40cu: goto label_17a40c;
        case 0x17a424u: goto label_17a424;
        case 0x17a48cu: goto label_17a48c;
        case 0x17a4a4u: goto label_17a4a4;
        default: break;
    }

    ctx->pc = 0x17a158u;

    // 0x17a158: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17a158u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17a15c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a15cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a160: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x17a160u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x17a164: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17a164u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a168: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17a168u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17a16c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17a16cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17a170: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17a170u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17a174: 0xc05e756  jal         func_179D58
    ctx->pc = 0x17A174u;
    SET_GPR_U32(ctx, 31, 0x17A17Cu);
    ctx->pc = 0x17A178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A174u;
            // 0x17a178: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A17Cu; }
        if (ctx->pc != 0x17A17Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A17Cu; }
        if (ctx->pc != 0x17A17Cu) { return; }
    }
    ctx->pc = 0x17A17Cu;
label_17a17c:
    // 0x17a17c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x17a17cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a180: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17a180u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a184: 0x12200008  beqz        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x17A184u;
    {
        const bool branch_taken_0x17a184 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A188u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A184u;
            // 0x17a188: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a184) {
            ctx->pc = 0x17A1A8u;
            goto label_17a1a8;
        }
    }
    ctx->pc = 0x17A18Cu;
    // 0x17a18c: 0xc05e966  jal         func_17A598
    ctx->pc = 0x17A18Cu;
    SET_GPR_U32(ctx, 31, 0x17A194u);
    ctx->pc = 0x17A598u;
    if (runtime->hasFunction(0x17A598u)) {
        auto targetFn = runtime->lookupFunction(0x17A598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A194u; }
        if (ctx->pc != 0x17A194u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A598_0x17a598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A194u; }
        if (ctx->pc != 0x17A194u) { return; }
    }
    ctx->pc = 0x17A194u;
label_17a194:
    // 0x17a194: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17A194u;
    {
        const bool branch_taken_0x17a194 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A194u;
            // 0x17a198: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a194) {
            ctx->pc = 0x17A1ACu;
            goto label_17a1ac;
        }
    }
    ctx->pc = 0x17A19Cu;
    // 0x17a19c: 0x92230021  lbu         $v1, 0x21($s1)
    ctx->pc = 0x17a19cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 33)));
    // 0x17a1a0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17a1a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17a1a4: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x17a1a4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_17a1a8:
    // 0x17a1a8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a1a8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17a1ac:
    // 0x17a1ac: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a1acu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a1b0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a1b0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a1b4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17a1b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a1b8: 0x3e00008  jr          $ra
    ctx->pc = 0x17A1B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A1BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A1B8u;
            // 0x17a1bc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A17Cu: goto label_17a17c;
            case 0x17A194u: goto label_17a194;
            case 0x17A1A8u: goto label_17a1a8;
            case 0x17A1ACu: goto label_17a1ac;
            case 0x17A1E4u: goto label_17a1e4;
            case 0x17A1FCu: goto label_17a1fc;
            case 0x17A210u: goto label_17a210;
            case 0x17A214u: goto label_17a214;
            case 0x17A24Cu: goto label_17a24c;
            case 0x17A264u: goto label_17a264;
            case 0x17A27Cu: goto label_17a27c;
            case 0x17A280u: goto label_17a280;
            case 0x17A2BCu: goto label_17a2bc;
            case 0x17A2D4u: goto label_17a2d4;
            case 0x17A2F0u: goto label_17a2f0;
            case 0x17A2F4u: goto label_17a2f4;
            case 0x17A32Cu: goto label_17a32c;
            case 0x17A344u: goto label_17a344;
            case 0x17A358u: goto label_17a358;
            case 0x17A35Cu: goto label_17a35c;
            case 0x17A394u: goto label_17a394;
            case 0x17A3ACu: goto label_17a3ac;
            case 0x17A3CCu: goto label_17a3cc;
            case 0x17A3D0u: goto label_17a3d0;
            case 0x17A3D4u: goto label_17a3d4;
            case 0x17A40Cu: goto label_17a40c;
            case 0x17A424u: goto label_17a424;
            case 0x17A444u: goto label_17a444;
            case 0x17A448u: goto label_17a448;
            case 0x17A44Cu: goto label_17a44c;
            case 0x17A48Cu: goto label_17a48c;
            case 0x17A4A4u: goto label_17a4a4;
            case 0x17A4C8u: goto label_17a4c8;
            case 0x17A4CCu: goto label_17a4cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A1C0u;
    // 0x17a1c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17a1c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17a1c4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a1c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a1c8: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x17a1c8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x17a1cc: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17a1ccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a1d0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17a1d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17a1d4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17a1d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17a1d8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17a1d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17a1dc: 0xc05e756  jal         func_179D58
    ctx->pc = 0x17A1DCu;
    SET_GPR_U32(ctx, 31, 0x17A1E4u);
    ctx->pc = 0x17A1E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A1DCu;
            // 0x17a1e0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A1E4u; }
        if (ctx->pc != 0x17A1E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A1E4u; }
        if (ctx->pc != 0x17A1E4u) { return; }
    }
    ctx->pc = 0x17A1E4u;
label_17a1e4:
    // 0x17a1e4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x17a1e4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a1e8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17a1e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a1ec: 0x12200008  beqz        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x17A1ECu;
    {
        const bool branch_taken_0x17a1ec = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A1F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A1ECu;
            // 0x17a1f0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a1ec) {
            ctx->pc = 0x17A210u;
            goto label_17a210;
        }
    }
    ctx->pc = 0x17A1F4u;
    // 0x17a1f4: 0xc05e966  jal         func_17A598
    ctx->pc = 0x17A1F4u;
    SET_GPR_U32(ctx, 31, 0x17A1FCu);
    ctx->pc = 0x17A598u;
    if (runtime->hasFunction(0x17A598u)) {
        auto targetFn = runtime->lookupFunction(0x17A598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A1FCu; }
        if (ctx->pc != 0x17A1FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A598_0x17a598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A1FCu; }
        if (ctx->pc != 0x17A1FCu) { return; }
    }
    ctx->pc = 0x17A1FCu;
label_17a1fc:
    // 0x17a1fc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17A1FCu;
    {
        const bool branch_taken_0x17a1fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A1FCu;
            // 0x17a200: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a1fc) {
            ctx->pc = 0x17A214u;
            goto label_17a214;
        }
    }
    ctx->pc = 0x17A204u;
    // 0x17a204: 0x92230022  lbu         $v1, 0x22($s1)
    ctx->pc = 0x17a204u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 34)));
    // 0x17a208: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17a208u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17a20c: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x17a20cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_17a210:
    // 0x17a210: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a210u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17a214:
    // 0x17a214: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a214u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a218: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a218u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a21c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17a21cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a220: 0x3e00008  jr          $ra
    ctx->pc = 0x17A220u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A224u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A220u;
            // 0x17a224: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A17Cu: goto label_17a17c;
            case 0x17A194u: goto label_17a194;
            case 0x17A1A8u: goto label_17a1a8;
            case 0x17A1ACu: goto label_17a1ac;
            case 0x17A1E4u: goto label_17a1e4;
            case 0x17A1FCu: goto label_17a1fc;
            case 0x17A210u: goto label_17a210;
            case 0x17A214u: goto label_17a214;
            case 0x17A24Cu: goto label_17a24c;
            case 0x17A264u: goto label_17a264;
            case 0x17A27Cu: goto label_17a27c;
            case 0x17A280u: goto label_17a280;
            case 0x17A2BCu: goto label_17a2bc;
            case 0x17A2D4u: goto label_17a2d4;
            case 0x17A2F0u: goto label_17a2f0;
            case 0x17A2F4u: goto label_17a2f4;
            case 0x17A32Cu: goto label_17a32c;
            case 0x17A344u: goto label_17a344;
            case 0x17A358u: goto label_17a358;
            case 0x17A35Cu: goto label_17a35c;
            case 0x17A394u: goto label_17a394;
            case 0x17A3ACu: goto label_17a3ac;
            case 0x17A3CCu: goto label_17a3cc;
            case 0x17A3D0u: goto label_17a3d0;
            case 0x17A3D4u: goto label_17a3d4;
            case 0x17A40Cu: goto label_17a40c;
            case 0x17A424u: goto label_17a424;
            case 0x17A444u: goto label_17a444;
            case 0x17A448u: goto label_17a448;
            case 0x17A44Cu: goto label_17a44c;
            case 0x17A48Cu: goto label_17a48c;
            case 0x17A4A4u: goto label_17a4a4;
            case 0x17A4C8u: goto label_17a4c8;
            case 0x17A4CCu: goto label_17a4cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A228u;
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
            case 0x17A17Cu: goto label_17a17c;
            case 0x17A194u: goto label_17a194;
            case 0x17A1A8u: goto label_17a1a8;
            case 0x17A1ACu: goto label_17a1ac;
            case 0x17A1E4u: goto label_17a1e4;
            case 0x17A1FCu: goto label_17a1fc;
            case 0x17A210u: goto label_17a210;
            case 0x17A214u: goto label_17a214;
            case 0x17A24Cu: goto label_17a24c;
            case 0x17A264u: goto label_17a264;
            case 0x17A27Cu: goto label_17a27c;
            case 0x17A280u: goto label_17a280;
            case 0x17A2BCu: goto label_17a2bc;
            case 0x17A2D4u: goto label_17a2d4;
            case 0x17A2F0u: goto label_17a2f0;
            case 0x17A2F4u: goto label_17a2f4;
            case 0x17A32Cu: goto label_17a32c;
            case 0x17A344u: goto label_17a344;
            case 0x17A358u: goto label_17a358;
            case 0x17A35Cu: goto label_17a35c;
            case 0x17A394u: goto label_17a394;
            case 0x17A3ACu: goto label_17a3ac;
            case 0x17A3CCu: goto label_17a3cc;
            case 0x17A3D0u: goto label_17a3d0;
            case 0x17A3D4u: goto label_17a3d4;
            case 0x17A40Cu: goto label_17a40c;
            case 0x17A424u: goto label_17a424;
            case 0x17A444u: goto label_17a444;
            case 0x17A448u: goto label_17a448;
            case 0x17A44Cu: goto label_17a44c;
            case 0x17A48Cu: goto label_17a48c;
            case 0x17A4A4u: goto label_17a4a4;
            case 0x17A4C8u: goto label_17a4c8;
            case 0x17A4CCu: goto label_17a4cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A294u;
    // 0x17a294: 0x0  nop
    ctx->pc = 0x17a294u;
    // NOP
    // 0x17a298: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17a298u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17a29c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a29cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a2a0: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x17a2a0u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x17a2a4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17a2a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a2a8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17a2a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17a2ac: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17a2acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17a2b0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17a2b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17a2b4: 0xc05e756  jal         func_179D58
    ctx->pc = 0x17A2B4u;
    SET_GPR_U32(ctx, 31, 0x17A2BCu);
    ctx->pc = 0x17A2B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A2B4u;
            // 0x17a2b8: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A2BCu; }
        if (ctx->pc != 0x17A2BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A2BCu; }
        if (ctx->pc != 0x17A2BCu) { return; }
    }
    ctx->pc = 0x17A2BCu;
label_17a2bc:
    // 0x17a2bc: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x17a2bcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a2c0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17a2c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a2c4: 0x1220000a  beqz        $s1, . + 4 + (0xA << 2)
    ctx->pc = 0x17A2C4u;
    {
        const bool branch_taken_0x17a2c4 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A2C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A2C4u;
            // 0x17a2c8: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a2c4) {
            ctx->pc = 0x17A2F0u;
            goto label_17a2f0;
        }
    }
    ctx->pc = 0x17A2CCu;
    // 0x17a2cc: 0xc05e966  jal         func_17A598
    ctx->pc = 0x17A2CCu;
    SET_GPR_U32(ctx, 31, 0x17A2D4u);
    ctx->pc = 0x17A598u;
    if (runtime->hasFunction(0x17A598u)) {
        auto targetFn = runtime->lookupFunction(0x17A598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A2D4u; }
        if (ctx->pc != 0x17A2D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A598_0x17a598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A2D4u; }
        if (ctx->pc != 0x17A2D4u) { return; }
    }
    ctx->pc = 0x17A2D4u;
label_17a2d4:
    // 0x17a2d4: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x17A2D4u;
    {
        const bool branch_taken_0x17a2d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A2D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A2D4u;
            // 0x17a2d8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a2d4) {
            ctx->pc = 0x17A2F4u;
            goto label_17a2f4;
        }
    }
    ctx->pc = 0x17A2DCu;
    // 0x17a2dc: 0x92230023  lbu         $v1, 0x23($s1)
    ctx->pc = 0x17a2dcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 35)));
    // 0x17a2e0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17a2e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17a2e4: 0x30630010  andi        $v1, $v1, 0x10
    ctx->pc = 0x17a2e4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)16);
    // 0x17a2e8: 0x3182b  sltu        $v1, $zero, $v1
    ctx->pc = 0x17a2e8u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x17a2ec: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x17a2ecu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_17a2f0:
    // 0x17a2f0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a2f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17a2f4:
    // 0x17a2f4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a2f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a2f8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a2f8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a2fc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17a2fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a300: 0x3e00008  jr          $ra
    ctx->pc = 0x17A300u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A300u;
            // 0x17a304: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A17Cu: goto label_17a17c;
            case 0x17A194u: goto label_17a194;
            case 0x17A1A8u: goto label_17a1a8;
            case 0x17A1ACu: goto label_17a1ac;
            case 0x17A1E4u: goto label_17a1e4;
            case 0x17A1FCu: goto label_17a1fc;
            case 0x17A210u: goto label_17a210;
            case 0x17A214u: goto label_17a214;
            case 0x17A24Cu: goto label_17a24c;
            case 0x17A264u: goto label_17a264;
            case 0x17A27Cu: goto label_17a27c;
            case 0x17A280u: goto label_17a280;
            case 0x17A2BCu: goto label_17a2bc;
            case 0x17A2D4u: goto label_17a2d4;
            case 0x17A2F0u: goto label_17a2f0;
            case 0x17A2F4u: goto label_17a2f4;
            case 0x17A32Cu: goto label_17a32c;
            case 0x17A344u: goto label_17a344;
            case 0x17A358u: goto label_17a358;
            case 0x17A35Cu: goto label_17a35c;
            case 0x17A394u: goto label_17a394;
            case 0x17A3ACu: goto label_17a3ac;
            case 0x17A3CCu: goto label_17a3cc;
            case 0x17A3D0u: goto label_17a3d0;
            case 0x17A3D4u: goto label_17a3d4;
            case 0x17A40Cu: goto label_17a40c;
            case 0x17A424u: goto label_17a424;
            case 0x17A444u: goto label_17a444;
            case 0x17A448u: goto label_17a448;
            case 0x17A44Cu: goto label_17a44c;
            case 0x17A48Cu: goto label_17a48c;
            case 0x17A4A4u: goto label_17a4a4;
            case 0x17A4C8u: goto label_17a4c8;
            case 0x17A4CCu: goto label_17a4cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A308u;
    // 0x17a308: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17a308u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17a30c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a30cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a310: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x17a310u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x17a314: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17a314u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a318: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17a318u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17a31c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17a31cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17a320: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17a320u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17a324: 0xc05e756  jal         func_179D58
    ctx->pc = 0x17A324u;
    SET_GPR_U32(ctx, 31, 0x17A32Cu);
    ctx->pc = 0x17A328u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A324u;
            // 0x17a328: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A32Cu; }
        if (ctx->pc != 0x17A32Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A32Cu; }
        if (ctx->pc != 0x17A32Cu) { return; }
    }
    ctx->pc = 0x17A32Cu;
label_17a32c:
    // 0x17a32c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x17a32cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a330: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17a330u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a334: 0x12200008  beqz        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x17A334u;
    {
        const bool branch_taken_0x17a334 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A334u;
            // 0x17a338: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a334) {
            ctx->pc = 0x17A358u;
            goto label_17a358;
        }
    }
    ctx->pc = 0x17A33Cu;
    // 0x17a33c: 0xc05e966  jal         func_17A598
    ctx->pc = 0x17A33Cu;
    SET_GPR_U32(ctx, 31, 0x17A344u);
    ctx->pc = 0x17A598u;
    if (runtime->hasFunction(0x17A598u)) {
        auto targetFn = runtime->lookupFunction(0x17A598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A344u; }
        if (ctx->pc != 0x17A344u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A598_0x17a598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A344u; }
        if (ctx->pc != 0x17A344u) { return; }
    }
    ctx->pc = 0x17A344u;
label_17a344:
    // 0x17a344: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17A344u;
    {
        const bool branch_taken_0x17a344 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A344u;
            // 0x17a348: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a344) {
            ctx->pc = 0x17A35Cu;
            goto label_17a35c;
        }
    }
    ctx->pc = 0x17A34Cu;
    // 0x17a34c: 0x92230024  lbu         $v1, 0x24($s1)
    ctx->pc = 0x17a34cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x17a350: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17a350u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17a354: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x17a354u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_17a358:
    // 0x17a358: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a358u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17a35c:
    // 0x17a35c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a35cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a360: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a360u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a364: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17a364u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a368: 0x3e00008  jr          $ra
    ctx->pc = 0x17A368u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A36Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A368u;
            // 0x17a36c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A17Cu: goto label_17a17c;
            case 0x17A194u: goto label_17a194;
            case 0x17A1A8u: goto label_17a1a8;
            case 0x17A1ACu: goto label_17a1ac;
            case 0x17A1E4u: goto label_17a1e4;
            case 0x17A1FCu: goto label_17a1fc;
            case 0x17A210u: goto label_17a210;
            case 0x17A214u: goto label_17a214;
            case 0x17A24Cu: goto label_17a24c;
            case 0x17A264u: goto label_17a264;
            case 0x17A27Cu: goto label_17a27c;
            case 0x17A280u: goto label_17a280;
            case 0x17A2BCu: goto label_17a2bc;
            case 0x17A2D4u: goto label_17a2d4;
            case 0x17A2F0u: goto label_17a2f0;
            case 0x17A2F4u: goto label_17a2f4;
            case 0x17A32Cu: goto label_17a32c;
            case 0x17A344u: goto label_17a344;
            case 0x17A358u: goto label_17a358;
            case 0x17A35Cu: goto label_17a35c;
            case 0x17A394u: goto label_17a394;
            case 0x17A3ACu: goto label_17a3ac;
            case 0x17A3CCu: goto label_17a3cc;
            case 0x17A3D0u: goto label_17a3d0;
            case 0x17A3D4u: goto label_17a3d4;
            case 0x17A40Cu: goto label_17a40c;
            case 0x17A424u: goto label_17a424;
            case 0x17A444u: goto label_17a444;
            case 0x17A448u: goto label_17a448;
            case 0x17A44Cu: goto label_17a44c;
            case 0x17A48Cu: goto label_17a48c;
            case 0x17A4A4u: goto label_17a4a4;
            case 0x17A4C8u: goto label_17a4c8;
            case 0x17A4CCu: goto label_17a4cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A370u;
    // 0x17a370: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17a370u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17a374: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a374u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a378: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x17a378u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x17a37c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17a37cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a380: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17a380u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17a384: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17a384u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17a388: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17a388u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17a38c: 0xc05e756  jal         func_179D58
    ctx->pc = 0x17A38Cu;
    SET_GPR_U32(ctx, 31, 0x17A394u);
    ctx->pc = 0x17A390u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A38Cu;
            // 0x17a390: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A394u; }
        if (ctx->pc != 0x17A394u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A394u; }
        if (ctx->pc != 0x17A394u) { return; }
    }
    ctx->pc = 0x17A394u;
label_17a394:
    // 0x17a394: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x17a394u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a398: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17a398u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a39c: 0x1220000c  beqz        $s1, . + 4 + (0xC << 2)
    ctx->pc = 0x17A39Cu;
    {
        const bool branch_taken_0x17a39c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A3A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A39Cu;
            // 0x17a3a0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a39c) {
            ctx->pc = 0x17A3D0u;
            goto label_17a3d0;
        }
    }
    ctx->pc = 0x17A3A4u;
    // 0x17a3a4: 0xc05e966  jal         func_17A598
    ctx->pc = 0x17A3A4u;
    SET_GPR_U32(ctx, 31, 0x17A3ACu);
    ctx->pc = 0x17A598u;
    if (runtime->hasFunction(0x17A598u)) {
        auto targetFn = runtime->lookupFunction(0x17A598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A3ACu; }
        if (ctx->pc != 0x17A3ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A598_0x17a598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A3ACu; }
        if (ctx->pc != 0x17A3ACu) { return; }
    }
    ctx->pc = 0x17A3ACu;
label_17a3ac:
    // 0x17a3ac: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x17A3ACu;
    {
        const bool branch_taken_0x17a3ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A3B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A3ACu;
            // 0x17a3b0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a3ac) {
            ctx->pc = 0x17A3D4u;
            goto label_17a3d4;
        }
    }
    ctx->pc = 0x17A3B4u;
    // 0x17a3b4: 0x92220025  lbu         $v0, 0x25($s1)
    ctx->pc = 0x17a3b4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 37)));
    // 0x17a3b8: 0x28430040  slti        $v1, $v0, 0x40
    ctx->pc = 0x17a3b8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x17a3bc: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x17A3BCu;
    {
        const bool branch_taken_0x17a3bc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x17A3C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A3BCu;
            // 0x17a3c0: 0xae420000  sw          $v0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a3bc) {
            ctx->pc = 0x17A3CCu;
            goto label_17a3cc;
        }
    }
    ctx->pc = 0x17A3C4u;
    // 0x17a3c4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x17a3c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x17a3c8: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x17a3c8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
label_17a3cc:
    // 0x17a3cc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17a3ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_17a3d0:
    // 0x17a3d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a3d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17a3d4:
    // 0x17a3d4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a3d4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a3d8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a3d8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a3dc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17a3dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a3e0: 0x3e00008  jr          $ra
    ctx->pc = 0x17A3E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A3E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A3E0u;
            // 0x17a3e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A17Cu: goto label_17a17c;
            case 0x17A194u: goto label_17a194;
            case 0x17A1A8u: goto label_17a1a8;
            case 0x17A1ACu: goto label_17a1ac;
            case 0x17A1E4u: goto label_17a1e4;
            case 0x17A1FCu: goto label_17a1fc;
            case 0x17A210u: goto label_17a210;
            case 0x17A214u: goto label_17a214;
            case 0x17A24Cu: goto label_17a24c;
            case 0x17A264u: goto label_17a264;
            case 0x17A27Cu: goto label_17a27c;
            case 0x17A280u: goto label_17a280;
            case 0x17A2BCu: goto label_17a2bc;
            case 0x17A2D4u: goto label_17a2d4;
            case 0x17A2F0u: goto label_17a2f0;
            case 0x17A2F4u: goto label_17a2f4;
            case 0x17A32Cu: goto label_17a32c;
            case 0x17A344u: goto label_17a344;
            case 0x17A358u: goto label_17a358;
            case 0x17A35Cu: goto label_17a35c;
            case 0x17A394u: goto label_17a394;
            case 0x17A3ACu: goto label_17a3ac;
            case 0x17A3CCu: goto label_17a3cc;
            case 0x17A3D0u: goto label_17a3d0;
            case 0x17A3D4u: goto label_17a3d4;
            case 0x17A40Cu: goto label_17a40c;
            case 0x17A424u: goto label_17a424;
            case 0x17A444u: goto label_17a444;
            case 0x17A448u: goto label_17a448;
            case 0x17A44Cu: goto label_17a44c;
            case 0x17A48Cu: goto label_17a48c;
            case 0x17A4A4u: goto label_17a4a4;
            case 0x17A4C8u: goto label_17a4c8;
            case 0x17A4CCu: goto label_17a4cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A3E8u;
    // 0x17a3e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17a3e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17a3ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a3ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a3f0: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x17a3f0u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x17a3f4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17a3f4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a3f8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17a3f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17a3fc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17a3fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17a400: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17a400u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17a404: 0xc05e756  jal         func_179D58
    ctx->pc = 0x17A404u;
    SET_GPR_U32(ctx, 31, 0x17A40Cu);
    ctx->pc = 0x17A408u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A404u;
            // 0x17a408: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A40Cu; }
        if (ctx->pc != 0x17A40Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A40Cu; }
        if (ctx->pc != 0x17A40Cu) { return; }
    }
    ctx->pc = 0x17A40Cu;
label_17a40c:
    // 0x17a40c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x17a40cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a410: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17a410u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a414: 0x1220000c  beqz        $s1, . + 4 + (0xC << 2)
    ctx->pc = 0x17A414u;
    {
        const bool branch_taken_0x17a414 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A414u;
            // 0x17a418: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a414) {
            ctx->pc = 0x17A448u;
            goto label_17a448;
        }
    }
    ctx->pc = 0x17A41Cu;
    // 0x17a41c: 0xc05e966  jal         func_17A598
    ctx->pc = 0x17A41Cu;
    SET_GPR_U32(ctx, 31, 0x17A424u);
    ctx->pc = 0x17A598u;
    if (runtime->hasFunction(0x17A598u)) {
        auto targetFn = runtime->lookupFunction(0x17A598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A424u; }
        if (ctx->pc != 0x17A424u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A598_0x17a598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A424u; }
        if (ctx->pc != 0x17A424u) { return; }
    }
    ctx->pc = 0x17A424u;
label_17a424:
    // 0x17a424: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x17A424u;
    {
        const bool branch_taken_0x17a424 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A428u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A424u;
            // 0x17a428: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a424) {
            ctx->pc = 0x17A44Cu;
            goto label_17a44c;
        }
    }
    ctx->pc = 0x17A42Cu;
    // 0x17a42c: 0x92220026  lbu         $v0, 0x26($s1)
    ctx->pc = 0x17a42cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 38)));
    // 0x17a430: 0x28430040  slti        $v1, $v0, 0x40
    ctx->pc = 0x17a430u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x17a434: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x17A434u;
    {
        const bool branch_taken_0x17a434 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x17A438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A434u;
            // 0x17a438: 0xae420000  sw          $v0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a434) {
            ctx->pc = 0x17A444u;
            goto label_17a444;
        }
    }
    ctx->pc = 0x17A43Cu;
    // 0x17a43c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x17a43cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x17a440: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x17a440u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
label_17a444:
    // 0x17a444: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17a444u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_17a448:
    // 0x17a448: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a448u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17a44c:
    // 0x17a44c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a44cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a450: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a450u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a454: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17a454u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a458: 0x3e00008  jr          $ra
    ctx->pc = 0x17A458u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A45Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A458u;
            // 0x17a45c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A17Cu: goto label_17a17c;
            case 0x17A194u: goto label_17a194;
            case 0x17A1A8u: goto label_17a1a8;
            case 0x17A1ACu: goto label_17a1ac;
            case 0x17A1E4u: goto label_17a1e4;
            case 0x17A1FCu: goto label_17a1fc;
            case 0x17A210u: goto label_17a210;
            case 0x17A214u: goto label_17a214;
            case 0x17A24Cu: goto label_17a24c;
            case 0x17A264u: goto label_17a264;
            case 0x17A27Cu: goto label_17a27c;
            case 0x17A280u: goto label_17a280;
            case 0x17A2BCu: goto label_17a2bc;
            case 0x17A2D4u: goto label_17a2d4;
            case 0x17A2F0u: goto label_17a2f0;
            case 0x17A2F4u: goto label_17a2f4;
            case 0x17A32Cu: goto label_17a32c;
            case 0x17A344u: goto label_17a344;
            case 0x17A358u: goto label_17a358;
            case 0x17A35Cu: goto label_17a35c;
            case 0x17A394u: goto label_17a394;
            case 0x17A3ACu: goto label_17a3ac;
            case 0x17A3CCu: goto label_17a3cc;
            case 0x17A3D0u: goto label_17a3d0;
            case 0x17A3D4u: goto label_17a3d4;
            case 0x17A40Cu: goto label_17a40c;
            case 0x17A424u: goto label_17a424;
            case 0x17A444u: goto label_17a444;
            case 0x17A448u: goto label_17a448;
            case 0x17A44Cu: goto label_17a44c;
            case 0x17A48Cu: goto label_17a48c;
            case 0x17A4A4u: goto label_17a4a4;
            case 0x17A4C8u: goto label_17a4c8;
            case 0x17A4CCu: goto label_17a4cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A460u;
    // 0x17a460: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17a460u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17a464: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a464u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a468: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x17a468u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x17a46c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17a46cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a470: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17a470u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17a474: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17a474u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17a478: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17a478u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a47c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x17a47cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x17a480: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17a480u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17a484: 0xc05e756  jal         func_179D58
    ctx->pc = 0x17A484u;
    SET_GPR_U32(ctx, 31, 0x17A48Cu);
    ctx->pc = 0x17A488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A484u;
            // 0x17a488: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A48Cu; }
        if (ctx->pc != 0x17A48Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A48Cu; }
        if (ctx->pc != 0x17A48Cu) { return; }
    }
    ctx->pc = 0x17A48Cu;
label_17a48c:
    // 0x17a48c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x17a48cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a490: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17a490u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a494: 0x1220000c  beqz        $s1, . + 4 + (0xC << 2)
    ctx->pc = 0x17A494u;
    {
        const bool branch_taken_0x17a494 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A494u;
            // 0x17a498: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a494) {
            ctx->pc = 0x17A4C8u;
            goto label_17a4c8;
        }
    }
    ctx->pc = 0x17A49Cu;
    // 0x17a49c: 0xc05e966  jal         func_17A598
    ctx->pc = 0x17A49Cu;
    SET_GPR_U32(ctx, 31, 0x17A4A4u);
    ctx->pc = 0x17A598u;
    if (runtime->hasFunction(0x17A598u)) {
        auto targetFn = runtime->lookupFunction(0x17A598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A4A4u; }
        if (ctx->pc != 0x17A4A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A598_0x17a598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A4A4u; }
        if (ctx->pc != 0x17A4A4u) { return; }
    }
    ctx->pc = 0x17A4A4u;
label_17a4a4:
    // 0x17a4a4: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x17A4A4u;
    {
        const bool branch_taken_0x17a4a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A4A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A4A4u;
            // 0x17a4a8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a4a4) {
            ctx->pc = 0x17A4CCu;
            goto label_17a4cc;
        }
    }
    ctx->pc = 0x17A4ACu;
    // 0x17a4ac: 0x8e43000c  lw          $v1, 0xC($s2)
    ctx->pc = 0x17a4acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x17a4b0: 0x286300d2  slti        $v1, $v1, 0xD2
    ctx->pc = 0x17a4b0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)210) ? 1 : 0);
    // 0x17a4b4: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x17A4B4u;
    {
        const bool branch_taken_0x17a4b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x17A4B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A4B4u;
            // 0x17a4b8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a4b4) {
            ctx->pc = 0x17A4CCu;
            goto label_17a4cc;
        }
    }
    ctx->pc = 0x17A4BCu;
    // 0x17a4bc: 0x92230027  lbu         $v1, 0x27($s1)
    ctx->pc = 0x17a4bcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 39)));
    // 0x17a4c0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17a4c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17a4c4: 0xae630000  sw          $v1, 0x0($s3)
    ctx->pc = 0x17a4c4u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
label_17a4c8:
    // 0x17a4c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a4c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17a4cc:
    // 0x17a4cc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a4ccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a4d0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a4d0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a4d4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17a4d4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a4d8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17a4d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17a4dc: 0x3e00008  jr          $ra
    ctx->pc = 0x17A4DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A4E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A4DCu;
            // 0x17a4e0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A17Cu: goto label_17a17c;
            case 0x17A194u: goto label_17a194;
            case 0x17A1A8u: goto label_17a1a8;
            case 0x17A1ACu: goto label_17a1ac;
            case 0x17A1E4u: goto label_17a1e4;
            case 0x17A1FCu: goto label_17a1fc;
            case 0x17A210u: goto label_17a210;
            case 0x17A214u: goto label_17a214;
            case 0x17A24Cu: goto label_17a24c;
            case 0x17A264u: goto label_17a264;
            case 0x17A27Cu: goto label_17a27c;
            case 0x17A280u: goto label_17a280;
            case 0x17A2BCu: goto label_17a2bc;
            case 0x17A2D4u: goto label_17a2d4;
            case 0x17A2F0u: goto label_17a2f0;
            case 0x17A2F4u: goto label_17a2f4;
            case 0x17A32Cu: goto label_17a32c;
            case 0x17A344u: goto label_17a344;
            case 0x17A358u: goto label_17a358;
            case 0x17A35Cu: goto label_17a35c;
            case 0x17A394u: goto label_17a394;
            case 0x17A3ACu: goto label_17a3ac;
            case 0x17A3CCu: goto label_17a3cc;
            case 0x17A3D0u: goto label_17a3d0;
            case 0x17A3D4u: goto label_17a3d4;
            case 0x17A40Cu: goto label_17a40c;
            case 0x17A424u: goto label_17a424;
            case 0x17A444u: goto label_17a444;
            case 0x17A448u: goto label_17a448;
            case 0x17A44Cu: goto label_17a44c;
            case 0x17A48Cu: goto label_17a48c;
            case 0x17A4A4u: goto label_17a4a4;
            case 0x17A4C8u: goto label_17a4c8;
            case 0x17A4CCu: goto label_17a4cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A4E4u;
    // 0x17a4e4: 0x0  nop
    ctx->pc = 0x17a4e4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
